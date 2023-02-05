//17219_비밀번호 찾기
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    map<string,string> site_info;
    string site_addr, site_password;

    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> site_addr >> site_password;

        site_info[site_addr] = site_password;
    }

    for(int i=0; i<m; i++){
        string addr;
        cin >> addr;

        cout << site_info[addr] << "\n";
    }
}


//#include <iostream> //map 자료구조 사용 X (시간초과)
//#include <string>
//#include <vector>
//using namespace std;
//
//void InputSite(vector<std::string> &site_list, vector<std::string> &password_list, int num_of_site);
//void FindSite(vector<std::string> &site_list, vector<std::string> &password_list, int num_required_password);
//
//int main() {
//    cin.tie(nullptr);
//    ios::sync_with_stdio(false);
//
//    int num_site, num_required_password;
//    cin >> num_site >> num_required_password;
//
//    vector<std::string> info_site;
//    vector<std::string> info_password;
//
//    InputSite(info_site, info_password, num_site);
//    FindSite(info_site, info_password, num_required_password);
//
//    return 0;
//}
//
//void InputSite(vector<std::string> &site_list, vector<std::string> &password_list, int num_of_site){
//    for(int i=0; i<num_of_site; i++){
//        string site_input, password_input;
//
//        cin >> site_input >> password_input;
//
//        site_list.push_back(site_input);
//        password_list.push_back(password_input);
//    }
//}
//
//void FindSite(vector<std::string> &site_list, vector<std::string> &password_list, int num_required_password){
//    for(int i=0; i<num_required_password; i++){
//        std::string site_required_password;
//        cin >> site_required_password;
//
//        int index(0);
//        for(const auto& element: site_list){
//            if(site_required_password == element)
//                break;
//            ++index;
//        }
//
//        cout << password_list[index] << "\n";
//    }
//}