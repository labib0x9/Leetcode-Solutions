// https://leetcode.com/problems/flipping-an-image/
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for (int i = 0; i < n; i++) {
            // reverse each rows
            for (int j = 0; j < n / 2; j++) {
                swap(image[i][j], image[i][n - j - 1]);
                image[i][j] ^= 1;
                image[i][n - j - 1] ^= 1;
            }
            if (n & 1) {
                image[i][n / 2] ^= 1;
            }
        }
        return image;
    }
};