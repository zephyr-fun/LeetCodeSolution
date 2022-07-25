// 2022.07.24
class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> map;
    unordered_map<string, int> f2r;
    unordered_map<string, string> f2c;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++) {
            map[cuisines[i]].insert({-ratings[i], foods[i]});
            f2r[foods[i]] = ratings[i];
            f2c[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = f2c[food];
        int oldRating = f2r[food];
        map[cuisine].erase({-oldRating, food});
        map[cuisine].insert({-newRating, food});
        f2r[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return map[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */