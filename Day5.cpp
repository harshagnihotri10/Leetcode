class Solution {
  public int stoneGameII(int[] piles) {
    int n = piles.length;
    for (int i  = n - 2; i >= 0; i--) {
      piles[i] += piles[i+1];
    }
    if (n <= 2) {
      return piles[0];
    }
    int[][] dp = new int[n][(n+1)/2 + 1];
    for (int i = n-1; i >= 0; i--) {
      int sum = piles[i];
      int m = (n-i+1) / 2;
      dp[i][m] = sum;
      while (--m >= 1) {
        dp[i][m] = 0;
        for (int x = 1; x <= m*2 && i+x < n; x++) {
          int max = Math.min((n-i-x+1)/2, Math.max(x, m));
          dp[i][m] = Math.max(dp[i][m], sum - dp[i+x][max]);
        }
      }
    }
    return dp[0][1];
  }
}
