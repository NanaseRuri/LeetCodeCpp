#include "stdafx.h"

class Solution733FloodFill
{
	int _row;
	int _col;
	int _target;
	int _color;

public:
	void Dfs(vector<vector<int>>& image, int sr, int sc) {
		if (sr < 0 || sc < 0 || sr >= _row || sc >= _col || image[sr][sc] == _color) {
			return;
		}
		else {
			if (image[sr][sc] == _target) {
				image[sr][sc] = _color;

				Dfs(image, sr - 1, sc);
				Dfs(image, sr + 1, sc);
				Dfs(image, sr, sc - 1);
				Dfs(image, sr, sc + 1);
			}
		}
	}

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
		if (image[sr][sc] == color) {
			return image;
		}

		_row = image.size();
		_col = image[0].size();
		_color = color;
		_target = image[sr][sc];
		Dfs(image, sr, sc);
		return image;
	}
};
