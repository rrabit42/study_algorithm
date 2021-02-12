    // 테스트 몇개는 맞고 몇개는 틀림
    // 이유를 모르겠음. 그리고 효율성은 모두 맞추지 못함..!(erase가 시간 복잡도가 높다고 함)
   // 게다가 2중 반복이니 O(n) * O(n) = O(n^2)
//     for(int i=0; i<completion.size(); i++){
//         for(int j=0; j<participant.size(); j++){
//             if(participant[j] == completion[i]){
//                 participant.erase(participant.begin()+j);
//             }
//         }
//     }
    
//     string answer = "";
    
//     for(int i=0; i<participant.size(); i++){
//         answer = participant[i];
//     }
//     return answer;





// C++ STL에서 std::sort 알고리즘은 O(nlogn) 시간복잡도를 보장한다. O(nlogn) + O(nlogn) + O(n) = O(nlogn) 시간복잡도를 가진다

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    // ** 정렬해서 순서대로 만들기!
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i=0; i<completion.size(); i++){
        if(participant[i] != completion[i]){
            return participant[i];
        }
    }
    
    // 루프 도는 동안 아무도 발견 못했으면 마지막 애가 완주 못한 것!
    return participant[participant.size()-1];
}


/*
hash 문제니까 map으로 풀어보자
C++의 STL에는 map와 unorderd_map 이 있고 둘 다 key value에 접근 가능.
map은 Red-Black Tree를 사용해 키의 순서를 유지하므로 탐색 속도에 시간복잡도 O(log n)을 가진다.
반면 unordered_map은 Hash Table을 사용해 키의 순서를 유지하지 않는다. key 분포에 따라 탐색 속도에 O(1) 이상의 시간복잡도를 가진다.

여기서는 이름이 정렬되어 있을 필요가 없으므로 unordered_map이 더 적합하고, 성능 또한 더 빠르다.

아래 문제 풀이는 O(n) + O(n) + O(n) = O(n) 시간복잡도를 가진다.

출처: https://boycoding.tistory.com/226 [소년코딩]
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    unordered_map<string, int> participants;
    for(string name: completion){
        // value 값 +1
        ++participants[name];
    }
    
    // auto 키워드를 사용하여 C++이 자료형을 추론하도록
    for(auto name: participant){
        // value 값 -1
        --participants[name];
        
        // 즉, completion에 있는 애들은 +1, -1이 되어 0이 됐을 것!
        // 완주하지 못한 애들은 -1만 되어있음
        if(participants[name] < 0) return name;
    }
}
