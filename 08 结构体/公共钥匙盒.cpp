#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Teacher {
    int key;  // ��Ҫ�Ľ���Կ�ױ��
    int startTime;  // ��ʼ�Ͽε�ʱ��
    int endTime;    // �¿�ʱ�䣨����Կ��ʱ�䣩
    bool returned = false;  // �Ƿ��ѻ�Կ��
};

// ��������
bool compareByKey(Teacher a, Teacher b);
void returnKeyToHooks(vector<int>& hooks, Teacher t);
void borrowKeyFromHooks(vector<int>& hooks, Teacher& t);

bool compareByKey(Teacher a, Teacher b) {
    return a.key < b.key;  // ����Կ�ױ����������
}

void returnKeyToHooks(vector<int>& hooks, Teacher t) {
    // ���ҵ�һ���չҹ�������Կ��
    auto it = find(hooks.begin(), hooks.end(), 0);
    if (it != hooks.end()) {
        *it = t.key;  // ��Կ�׷ŵ��չҹ���
    }
}

void borrowKeyFromHooks(vector<int>& hooks, Teacher& t) {
    // ����Կ�ײ�ȡ��
    auto it = find(hooks.begin(), hooks.end(), t.key);
    if (it != hooks.end()) {
        *it = 0;  // ��Կ�״ӹҹ���ȡ��
    }
}

int main() {
    int numHooks;  // Կ�׹ҹ�����
    cin >> numHooks;
    vector<int> hooks(numHooks);  // Կ�׹ҹ���״̬
    for (int i = 0; i < numHooks; i++) {
        hooks[i] = 1 + i;  // ��ʼ���ҹ��ϵ�Կ�ױ��
    }

    int numTeachers;  // ��ʦ������
    cin >> numTeachers;
    vector<Teacher> teachers(numTeachers);  // ��ʦ�ǵ���Ϣ
    for (int i = 0; i < numTeachers; i++) {
        cin >> teachers[i].key >> teachers[i].startTime >> teachers[i].endTime;
        teachers[i].endTime += teachers[i].startTime;  // �����¿�ʱ�䣬����Կ��ʱ��
    }

    int returnedKeys = 0;  // ��¼�ѻ�Կ�׵���ʦ����

    // ʹ��STL sort����Կ�ױ������
    sort(teachers.begin(), teachers.end(), compareByKey);

    // ������ʦ�ǵ��Ͽκͻ�Կ�׹���
    for (int currentTime = 1; returnedKeys < numTeachers; currentTime++) {
        // �ȴ������л�Կ�׵Ĳ���
        for (int i = 0; i < numTeachers; i++) {
            if (currentTime == teachers[i].endTime) {
                if (!teachers[i].returned) {
                    returnKeyToHooks(hooks, teachers[i]);
                    returnedKeys++;
                    teachers[i].returned = true;
                }
            }
        }

        // Ȼ��������ȡԿ�׵Ĳ���
        for (int i = 0; i < numTeachers; i++) {
            if (currentTime == teachers[i].startTime) {
                borrowKeyFromHooks(hooks, teachers[i]);
            }
        }
    }

    // ������յĹҹ�״̬��Կ�׵�˳��
    for (int i = 0; i < numHooks; i++) {
        cout << hooks[i] << " ";
    }

    return 0;
}
/*
������������

   ��һ��ѧУ����ʦ����N�����ң����չ涨�����е�Կ�׶�������ڹ���Կ�׺����ʦ���ܴ�Կ�׻ؼҡ�ÿ����ʦ�Ͽ�ǰ�����ӹ���Կ�׺����ҵ��Լ��ϿεĽ��ҵ�Կ��ȥ���ţ�����κ��ٽ�Կ�׷Żص�Կ�׺��С�
  ����Կ�׺�һ����N���ҹ����������ų�һ�ţ�������N�����ҵ�Կ�ס�һ��Կ��û�й̶�������λ�ã���Կ�����б�ʶ��������ʦ�ǲ���Ū��Կ�ס�
  ����ÿ��ȡԿ�׵�ʱ����ʦ�Ƕ����ҵ��Լ�����Ҫ��Կ�׽���ȡ�ߣ��������ƶ�����Կ�ס�ÿ�λ�Կ�׵�ʱ�򣬻�Կ�׵���ʦ���ҵ�����ߵĿյĹҹ�����Կ�׹�������ҹ��ϡ�����ж�λ��ʦ��Կ�ף������ǰ�Կ�ױ�Ŵ�С�����˳�򻹡����ͬһʱ�̼�����ʦ��Կ��������ʦȡԿ�ף�����ʦ�ǻ��Ƚ�Կ��ȫ����ȥ��ȡ����
  �������쿪ʼ��ʱ��Կ���ǰ���Ŵ�С�����˳�����Կ�׺���ġ���Kλ��ʦҪ�ϿΣ�����ÿλ��ʦ����Ҫ��Կ�ס���ʼ�Ͽε�ʱ����Ͽε�ʱ���������¿�ʱ����ǻ�Կ��ʱ�䣬��������Կ�׺�����Կ�׵�˳���������ģ�

��������ʽ��

   ����ĵ�һ�а�����������N, K��
  ����������K�У�ÿ����������w, s, c���ֱ��ʾһλ��ʦҪʹ�õ�Կ�ױ�š���ʼ�Ͽε�ʱ����Ͽε�ʱ���������ж�λ��ʦʹ��ͬһ��Կ�ף�������ʦʹ��Կ�׵�ʱ�䲻���ص���
  ������֤�����������������ʽ���㲻�ü�����ݺϷ��ԡ�

�������ʽ��

   ���һ�У�����N��������������������һ���ո�ָ������α�ʾÿ���ҹ��Ϲҵ�Կ�ױ�š�

����������1��

5 2
4 3 3
2 2 7

���������1��

1 4 3 2 5


����������2��

5 7
1 1 14
3 3 12
1 15 12
2 7 20
3 18 12
4 21 19
5 30 9

���������2��

1 2 3 5 4

������1˵����

   ��һλ��ʦ��ʱ��3��ʼʹ��4�Ž��ҵ�Կ�ף�ʹ��3��λʱ�䣬������ʱ��6��Կ�ס��ڶ�λ��ʦ��ʱ��2��ʼʹ��Կ�ף�ʹ��7��λʱ�䣬������ʱ��9��Կ�ס�
  ����ÿ���ؼ�ʱ�̺��Կ��״̬���£�X��ʾ�գ���
  ����ʱ��2��Ϊ1X345��
  ����ʱ��3��Ϊ1X3X5��
  ����ʱ��6��Ϊ143X5��
  ����ʱ��9��Ϊ14325��

�����ֱ�׼��
 */