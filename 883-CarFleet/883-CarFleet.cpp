// Last updated: 8/4/2026, 12:23:53 PM
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i=0;i<position.size();i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());
        double lft=0;
        int f=0;
        for(auto& car: cars) {
            double time = (double)(target-car.first)/car.second;
            if(time > lft) {
                f++;
                lft=time;
            }
        }
        return f;
    }
};