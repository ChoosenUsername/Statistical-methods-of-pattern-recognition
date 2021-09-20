#include <iostream>
#include <vector>

using namespace std;

vector<vector<unsigned char>> CreateMatrix() {
    
    int n = 0; //rows
    int m = 0; //cols
    
    try {
        cout << "amount of rows: ";
        cin >> n;
        if (n > 1024){
            throw n;
        }
    } catch (int n) {
        cout << "wrong number of rows: " << n;
    }

    try {
        cout << "amount of cols: ";
        cin >> m;
        if (m > 1024){
            throw m;
        }
    } catch (int m) {
        cout << "wrong number of cols: " << n;
    }

    vector<vector<unsigned char>> vec( n , vector<unsigned char> (m, 0));

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            vec[i][j] = (unsigned char) rand();
        }
    }

    return vec;
}


unsigned sum(vector<vector<unsigned char>> vec, int x, int y) {
    unsigned res = 0;
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            res += vec[i][j];
        }
    }
    return res;
}

//57449


vector<vector<unsigned short>> CreateIntegralImage(vector<vector<unsigned char>> vec) {
    int n = vec.size();
    int m = vec[0].size();
    vector<vector<unsigned short>> II( n , vector<unsigned short> (m, 0));

    int y_counter = 0;
    int x_counter = 0;
    while (x_counter != n)
    {
        cout << "x_counter: " << x_counter << endl;
        while (y_counter <= m)
        {
            auto full_sum = (unsigned short) (sum(vec,x_counter,y_counter) & 0xFFFF);
            II[x_counter][y_counter] = full_sum;
            y_counter += 1;
        }
        y_counter = 0;
        x_counter += 1;
    }

    return II;
}


unsigned GetRectSum(std::vector<std::vector<unsigned short>> II) {
    
    int x,y,h,w;
    x = y = h = w = 0;
    
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;

    try {
        cout << "h: ";
        cin >> h;
        if (h > 15){
            throw h;
        }
    }
    catch (int h){
        cout << "h: " << h << " is wrong number";
        return 1;
    }

    try {
        cout << "w: ";
        cin >> w;
        if (w > 15){
            throw w;
        }
    }
    catch (int w){
        cout << "w: " << w << " is wrong number";
        return 1;
    }

    cout << "size of rect is " << h+1 << " x " << w + 1 << endl;

    unsigned p1 = II[y-1][x-1];
	unsigned p2 = II[y-1][x + w];
	unsigned p3 = II[y + h][x-1];
	unsigned p4 = II[y + h][x + w];
    
    return (p1+p4) - (p2+p3);
}


int main(int argc, char** argv)
{
    
    auto mat = CreateMatrix();
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << (unsigned)mat[i][j] << "  ";
        }
        cout << endl;
    }

    cout << "---------------------------------" << endl;

    auto II = CreateIntegralImage(mat);
    
    

    for (int i = 0; i < II.size(); i++)
    {
        for (int j = 0; j < II[i].size(); j++)
        {
            cout << II[i][j] << "   ";
        }
        cout << endl;
    }

    unsigned res = GetRectSum(II);
    cout << res << endl;

    return 0;
}
