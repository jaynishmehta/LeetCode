class FoodRatings {
public:
    unordered_map<string,pair<string,int>>m1;
     unordered_map<string, set<pair<int, string>>> m2; // cus- {rating,food}
    
    FoodRatings(vector<string>& foods, vector<string>& cuisine, vector<int>& rating) {
        for(int i=0;i<foods.size();i++){
            
            m1[foods[i]]={cuisine[i],rating[i]};
             m2[cuisine[i]].insert({-rating[i], foods[i]});
            }

        }
    
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = m1[food];
        m2[cuisine].erase({-oldRating, food});
        m2[cuisine].insert({-newRating, food});
        m1[food] = {cuisine, newRating};
    }
    
    string highestRated(string cuisine) {
        return m2[cuisine].begin()->second;
    
    }

};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */