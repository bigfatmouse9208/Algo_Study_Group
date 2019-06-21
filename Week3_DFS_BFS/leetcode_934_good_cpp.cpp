class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
      const int dr[4] = {-1, 0, 1, 0};
      const int dc[4] = {0, -1, 0, 1};
      const int N = A.size();

      queue<pair<int, int>> q;
      vector<vector<bool>> seen(N, vector<bool>(N, false));
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (A[i][j]) {
            q.push({i, j});
            seen[i][j] = true;
            break;
          }
        }
        if (!q.empty()) {
          break;
        }
      }

      queue<pair<int, int>> border;
      while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        bool adjacentToZero = false;
        for (int k = 0; k < 4; k++) {
          int rr = r + dr[k];
          int cc = c + dc[k];
          if (rr >= 0 && rr < N && cc >= 0 && cc < N) {
            if (A[rr][cc]) {
              if (seen[rr][cc]) {
                continue;
              }
              q.emplace(rr, cc); // push_back for queue
              seen[rr][cc] = true;
            } else {
              adjacentToZero = true;
            }
          }
        }
        if (adjacentToZero) {
          border.emplace(r, c);
        }
      }

      int step = 0;
      while (!border.empty()) {
        for (int n = border.size(); n > 0; n--) {
          auto [r, c] = border.front(); border.pop();
          for (int k = 0; k < 4; k++) {
            int rr = r + dr[k];
            int cc = c + dc[k];
            if (rr >= 0 && rr < N && cc >= 0 && cc < N) {
              if (seen[rr][cc]) {
                continue;
              }
              if (A[rr][cc]) {
                return step;
              }
              border.emplace(rr, cc);
              seen[rr][cc] = true;
            }
          }
        }
        step++;
      }

      return -1;
    }
};
