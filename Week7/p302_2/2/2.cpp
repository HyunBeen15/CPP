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
    MyDic() {                   // 생성자
        nWords = 0;             // 처음에는 저장된 단어가 없음
    }

    void add(string eng, string kor) {   // 하나의 단어 추가
        if (nWords < MAXWORDS) {
            words[nWords].eng = eng;
            words[nWords].kor = kor;
            nWords++;
        }
    }

    void load(string filename) {         // 파일에서 단어 읽기
        ifstream fin(filename);

        if (!fin) {
            cout << "파일을 열 수 없습니다." << endl;
            return;
        }

        nWords = 0;   // 새로 읽어오기 위해 초기화

        string eng, kor;
        while (fin >> eng >> kor) {
            add(eng, kor);
        }

        fin.close();
    }

    void store(string filename) {        // 파일에 모든 단어 저장
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

    void print() {                       // 모든 단어를 화면에 출력
        for (int i = 0; i < nWords; i++) {
            cout << i << ": "
                 << words[i].eng << " - "
                 << words[i].kor << endl;
        }
    }

    string getEng(int id) {             // id번째 영어 단어 반환
        if (id >= 0 && id < nWords)
            return words[id].eng;
        return "";
    }

    string getKor(int id) {             // id번째 한글 설명 반환
        if (id >= 0 && id < nWords)
            return words[id].kor;
        return "";
    }
};