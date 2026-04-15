#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAXWORDS 100

struct WordPair {   // 하나의 단어 쌍을 위한 구조체
    string eng;     // 영어 단어
    string kor;     // 한글 설명
};

class MyDic {
    WordPair words[MAXWORDS];   // 저장된 단어 배열
    int nWords;                 // 현재 등록된 단어의 수

public:
    MyDic() {
        nWords = 0;
    }

    void add(string eng, string kor) {
        if (nWords < MAXWORDS) {
            words[nWords].eng = eng;
            words[nWords].kor = kor;
            nWords++;
        }
    }

    void load(string filename) {
        ifstream fin(filename);

        if (!fin) {
            cout << "파일을 열 수 없습니다." << endl;
            return;
        }

        nWords = 0;

        string eng, kor;
        while (fin >> eng >> kor) {
            add(eng, kor);
        }

        fin.close();
    }

    void store(string filename) {
        ofstream fout(filename);

        if (!fout) {
            cout << "파일을 만들 수 없습니다." << endl;
            return;
        }

        for (int i = 0; i < nWords; i++) {
            fout << words[i].eng << " " << words[i].kor << endl;
        }

        fout.close();
    }

    void print() {
        for (int i = 0; i < nWords; i++) {
            cout << i << ": "
                 << words[i].eng << " - "
                 << words[i].kor << endl;
        }
    }

    string getEng(int id) {
        if (id >= 0 && id < nWords)
            return words[id].eng;
        return "";
    }

    string getKor(int id) {
        if (id >= 0 && id < nWords)
            return words[id].kor;
        return "";
    }
};

int main() {
    MyDic dic;

    dic.add("car", "자동차");        // 단어 추가
    dic.add("self-driving", "자율주행");
    dic.add("computer", "컴퓨터");

    cout << "[현재 단어장]" << endl;
    dic.print();

    dic.store("words.txt");          // 파일에 저장
    cout << "\nwords.txt 파일에 저장했습니다." << endl;

    MyDic dic2;
    dic2.load("words.txt");          // 파일에서 읽기

    cout << "\n[파일에서 읽은 단어장]" << endl;
    dic2.print();

    cout << "\n0번 영어 단어: " << dic2.getEng(0) << endl;
    cout << "0번 한글 설명: " << dic2.getKor(0) << endl;

    return 0;
}