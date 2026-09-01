class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        vector<pair<int, int>> litter;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                } else if (classroom[r][c] == 'L') {
                    litter.push_back({r, c});
                }
            }
        }

        int k = litter.size();

        // litterId[r][c] = bit corresponding to this litter
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int i = 0; i < k; i++) {
            litterId[litter[i].first][litter[i].second] = i;
        }

        int fullMask = (1 << k) - 1;

        /*
            best[(r * n + c) * masks + mask]

            Stores the maximum energy with which this
            (r, c, mask) configuration has been reached.
        */
        int masks = 1 << k;

        vector<short> best(m * n * masks, -1);

        auto index = [&](int r, int c, int mask) {
            return ((r * n + c) * masks + mask);
        };

        struct State {
            int r, c;
            int mask;
            int energy;
        };

        queue<State> q;

        best[index(sr, sc, 0)] = energy;
        q.push({sr, sc, 0, energy});

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();

                if (mask == fullMask)
                    return moves;

                /*
                    R resets energy to full capacity.

                    This is also why we normalize the energy
                    before making the next move.
                */
                if (classroom[r][c] == 'R')
                    e = energy;

                // Can't make a move without energy.
                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n ||
                        classroom[nr][nc] == 'X') {
                        continue;
                    }

                    int ne = e - 1;
                    int nmask = mask;

                    // Collect litter.
                    if (classroom[nr][nc] == 'L') {
                        nmask |= (1 << litterId[nr][nc]);
                    }

                    // Entering R immediately restores energy.
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    int idx = index(nr, nc, nmask);

                    /*
                        Dominance pruning:

                        If we've already reached the same position
                        with the same collected litter and >= energy,
                        this state can never be better.
                    */
                    if (best[idx] >= ne)
                        continue;

                    best[idx] = ne;
                    q.push({nr, nc, nmask, ne});
                }
            }

            moves++;
        }

        return -1;
    }
};