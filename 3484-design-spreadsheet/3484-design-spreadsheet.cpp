class Spreadsheet {
    vector<vector<int>>sp;
    void func1(int &i, string &formula, vector<int>& v) {
        string val = "";
        while (i < formula.size() && isdigit(formula[i])) {
            val += formula[i];
            i++;
        }
        if (!val.empty()) {
            v.push_back(stoi(val));
        }
        if (i < formula.size() && formula[i] == '+') i++; // skip '+'
    }

    void func2(int &i, string &formula, vector<int>& v) {
        int row = formula[i] - 'A';
        i++;
        string val = "";
        while (i < formula.size() && isdigit(formula[i])) {
            val += formula[i];
            i++;
        }
        if (!val.empty()) {
            int col = stoi(val) - 1;
            v.push_back(sp[row][col]);
        }
        if (i < formula.size() && formula[i] == '+') i++; // skip '+'
    }

public:
    // vector<vector<int>>sp;
    Spreadsheet(int rows) {
        sp.resize(26,vector<int>(rows,0));
    }
    
    void setCell(string cell, int value) {
        int i= cell[0]-'A';
        int j = stoi(cell.substr(1)) - 1;
        sp[i][j]=value;
        // cout<<sp[i][j]<<endl;
    }
    
    void resetCell(string cell) {
        int i= cell[0]-'A';
        int j = stoi(cell.substr(1)) - 1;
        sp[i][j]=0;
    }
    
    int getValue(string formula) {
        int i = 1; // skip '='
        vector<int> v;
        while (i < formula.size()) {
            if (isdigit(formula[i])) {
                func1(i, formula, v);
            } else if (isalpha(formula[i])) {
                func2(i, formula, v);
            } else {
                i++; // skip unknown chars safely
            }
        }
        return v[0]+v[1];
        
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */