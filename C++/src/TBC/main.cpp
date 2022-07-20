#include <iostream>
#include <bitset>

using namespace std;

int main(){
    unsigned char option_viewed     = 0x01;
    unsigned char option_edited     = 0x02;
    unsigned char option_liked      = 0x04;
    unsigned char option_shared     = 0x08;
    unsigned char option_deleted    = 0x80;

    unsigned char my_article_flags = 0;

    cout << "option_viewed  => " <<std::bitset<8>(option_viewed) << endl;
    cout << "option_edited  => " <<std::bitset<8>(option_edited) << endl;
    cout << "option_liked   => " <<std::bitset<8>(option_liked) << endl;
    cout << "option_shared  => " <<std::bitset<8>(option_shared) << endl;
    cout << "option_deleted => " <<std::bitset<8>(option_deleted) << endl << endl;

    my_article_flags |= option_viewed;
    cout << "기사를 봤을 때" << endl << std::bitset<8>(my_article_flags) << endl << endl;

    my_article_flags |= option_liked;
    cout << "기사의 좋아요를 클릭했을 때 " << endl << std::bitset<8>(my_article_flags) << endl <<endl;

    my_article_flags ^= option_liked;
    cout << "기사의 좋아요를 다시 클릭햇을 때 " << endl << std::bitset<8>(my_article_flags) << endl << endl;

    if(my_article_flags & option_viewed){
        my_article_flags |= option_deleted;
        cout << "본 기사만 삭제할 때 " << endl << std::bitset<8>(my_article_flags) << endl << endl;
    }

    return 0;
}