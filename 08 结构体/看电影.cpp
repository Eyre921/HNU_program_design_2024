#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����һ���ṹ�����洢��ѧ�ҵ�����
struct Scientist {
    int lang;  // ��ѧ����Ϥ�����Ա��
};

// ����һ���ṹ�����洢��Ӱ����Ϣ
struct Movie {
    int audioLang;  // ��Ƶ���Ա��
    int subtitleLang;  // ��Ļ���Ա��
    int happyCount = 0;  // �ǳ����˵Ŀ�ѧ������
    int satisfiedCount = 0;  // ��������Ŀ�ѧ������
};

int main() {
    int n, m;
    cin >> n;  // �����ѧ�ҵ�����

    // �洢��ѧ������
    vector<Scientist> scientists(n);
    for (int i = 0; i < n; i++) {
        cin >> scientists[i].lang;  // ����ÿ����ѧ�ҵ�����
    }

    cin >> m;  // �����Ӱ������

    // �洢��Ӱ����
    vector<Movie> movies(m);

    // �����Ӱ����Ƶ����
    for (int i = 0; i < m; i++) {
        cin >> movies[i].audioLang;
    }

    // �����Ӱ����Ļ����
    for (int i = 0; i < m; i++) {
        cin >> movies[i].subtitleLang;
    }

    // ����ÿ����Ӱ�ġ��ǳ����ˡ��͡��������⡱�Ŀ�ѧ������
    for (const auto& sci : scientists) {
        for (auto& movie : movies) {
            if (sci.lang == movie.audioLang) {
                movie.happyCount++;  // ���ӡ��ǳ����ˡ�����
            }
            if (sci.lang == movie.subtitleLang) {
                movie.satisfiedCount++;  // ���ӡ��������⡱����
            }
        }
    }

    // ������е�Ӱ��û���κο�ѧ�ҡ��ǳ����ˡ������ "unsatisfied"
    bool allUnsatisfied = true;
    for (const auto& movie : movies) {
        if (movie.happyCount > 0) {
            allUnsatisfied = false;
            break;
        }
    }

    if (allUnsatisfied) {
        cout << "unsatisfied";
    } else {
        // �ҵ���󡰷ǳ����ˡ�������
        int maxHappy = 0;
        for (const auto& movie : movies) {
            maxHappy = max(maxHappy, movie.happyCount);
        }

        // �ҵ�����󡰷ǳ����ˡ������е���󡰻������⡱����
        int maxSatisfied = 0;
        for (const auto& movie : movies) {
            if (movie.happyCount == maxHappy) {
                maxSatisfied = max(maxSatisfied, movie.satisfiedCount);
            }
        }

        // ������з��������ĵ�Ӱ��ţ���1��ʼ��
        bool found = false;
        for (int i = 0; i < m; i++) {
            if (movies[i].happyCount == maxHappy && movies[i].satisfiedCount == maxSatisfied) {
                cout << i + 1 << " ";  // ������������ĵ�Ӱ���
                found = true;
            }
        }

        // ���û���ҵ����������ĵ�Ӱ�����"unsatisfied"
        if (!found) {
            cout << "unsatisfied";
        }
    }

    return 0;
}
/*
������������

       ���ϴ�ѧ���ھٰ�һ����Ҫ�Ĺ���ѧ�����飬��ϯ����� n λ��ѧ�����Բ�ͬ�Ĺ��ң�ÿλ��ѧ�Ҷ�ֻ��Ϥһ�����ԣ�Ϊ������������������е�������1~1000�����ֱ�����г���

       ���ϣ����췽�������п�ѧ��ȥ����Ӱ����ӰԺ���� m ����Ӱ��ÿ����Ӱ������������ͬ������������������Ƶ���Ժ���Ļ���Եı�š�����Ӱ�Ŀ�ѧ�ң��������Ϥ��Ӱ����Ƶ���ԣ�����ǳ����ˣ��������Ϥ��Ļ�����ԣ������������⣬��������ֶ�����Ϥ������е�������(��ע�⣬ÿ����Ӱ����Ƶ���Ժ���Ļ�������ǲ�ͬ��)��

       ��ѧ���Ǿ���һ��ȥ��ͬһ����Ӱ��������������ѡ���Ӱ��ʹ�÷ǳ����˵Ŀ�ѧ�ҵ����������ģ�����жಿ�����ĵ�Ӱ��������ѡ����ʹ��������Ŀ�ѧ�ҵ��������������жಿ����ȫ����������û�������ĵ�Ӱ�������"unsatisfied"��

��������ʽ��

       ����ĵ�һ��Ϊһ�������� n (1 �� n �� 200000)  ����ʾ��ѧ�ҵ�������

       �ڶ���Ϊ n ��������a1��a2��...��an (1 �� ai �� 1000)������ai ��ʾ�� i λ��ѧ����Ϥ�����Ա�š�

       �����а���һ��������m(1 �� m �� 200000)����ʾ��ӰԺ��ĵ�Ӱ��������Ŵ�1~m��

       �����а��� m �������� b1, b2, ..., bm (1 �� bj �� 1000)������ bj ��ʾ��  j ����Ӱ����Ƶ���ԡ�

        �����а��� m �������� c1, c2, ..., cm (1 �� cj �� 1000)������ cj ��ʾ��  j ����Ӱ����Ļ���ԡ�

         ���뱣֤ bj �� cj  ��

�������ʽ��

       ���Ϊ������������С���󣬱�ʾ��ѧ���ǿ���ȥѡ��ȥ���ĵ�Ӱ�ı�š����û�������ĵ�Ӱ�������"unsatisfied"��

���������롿

3
2 3 2
2
3 2
2 3
�����������

2
 */