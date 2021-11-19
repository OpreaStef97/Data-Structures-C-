#include "queue.h"
#include <string>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

/*
string* findBin(int n){
    //return your answers in the following result array
    string *result = new string[n];
    myQueue q(n);
    for(int i = 1; i <= n; i++) {
        int num = i;
        int cnt = 0;
        ull bin = 0;
        while(num) {
            ull p = pow(10,cnt);
            bin += num % 2 * p;
            num /= 2; 
            cnt++;
        }
        q.enqueue(bin);
    }
    int i = 0;
    while(!q.isEmpty()) {
        result[i] = to_string(q.getFront());
        q.dequeue();
        i++;
    }
    return result;
}
*/
/*
string * findBin(int n) {
  string * result = new string[n];
  myQueue queue(n + 1);
  queue.enqueue(1);

  string s1, s2;
  for (int i = 0; i < n; i++) {
    result[i] = to_string(queue.dequeue());
    s1 = result[i] + "0";
    s2 = result[i] + "1";
    queue.enqueue(stoi(s1));
    queue.enqueue(stoi(s2));
  }

  return result;
}


int main() {
    int n = 3;

    string* res = findBin(n);

    for(int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
}
*/

vector<string> findBin(int n) {
    vector<string> res(n);
    queue<int> q;
    q.push(1);
    string s1, s2;
    for(int i = 0; i < n; i++) {
        res[i] = to_string(q.front());
        q.pop();
        s1 = res[i] + "0";
        s2 = res[i] + "1";
        q.push(stoi(s1));
        q.push(stoi(s2));
    }
    return res;
} 


int main() {
    vector<string> res = findBin(3);

    for(auto &s : res) {
        cout << s << ' ';
    }
    cout << endl;
}