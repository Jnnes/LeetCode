#pragma once
#pragma once
#include "../Common.h"


// ���沿�ֿ�������������

class Solution {
public:
    /*
        1371. ÿ��Ԫ������ż���ε���ַ���������ż��Ԫ���ַ�����Ӵ���
        ��Ϊÿ���ַ�ֻ����ż���κ�����������״̬�����ң�����- ���� = ż����ż�� - ż�� = ż����
        ��ô�Ϳ���֪����ֻҪ��¼�˵�һ��״̬��λ�ã��Ժ�ÿ�ε���ͬ״̬��
        �Ǹ���λ�õ���״̬��1�γ��ֵ�λ�ã��������״γ��ָ�״̬��λ�ã����е�Ԫ���ַ��϶���ż���Ρ�

        ����״̬�ı�ʾ�����ǿ���ʹ�ö����ƣ�ÿһλ��ʾһ��Ԫ���ַ���ʹ���������תλ���ﵽ������ż��֮����л�

        ��Ҫ���˷ѽ���� pos[0] = 0;���Լ� pos[status] = i + 1;
    */
    int findTheLongestSubstring(string s) {
        int status = 0, ans = 0;
        vector<int> pos(32, -1);
        pos[0] = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'a')
                status ^= 1 << 0;
            else if (c == 'e')
                status ^= 1 << 1;
            else if (c == 'i')
                status ^= 1 << 2;
            else if (c == 'o')
                status ^= 1 << 3;
            else if (c == 'u')
                status ^= 1 << 4;

            if (pos[status] != -1)
                ans = max(ans, i + 1 - pos[status]);
            else
                pos[status] = i + 1;
            /*
               �����¼��λ����Ҫ+1��������Ҫ����pos[0] = 0��
               pos[0] = 0����Ϊ����ʼ�����һ����ĸ��ΪԪ������ôstatus = 0�����������Ԫ���ǿ��Լӵ����ż���Ӵ��ģ�
               �������ԭ���㷨��Ŀ�ģ�����״̬��λ�ü�ȥ��һ�γ���״̬��λ�ã���ô�����ǲ�������һ�γ��ֵ��Ǹ��ַ��ģ�
               ���ԣ�������ȳ��ַ�Ԫ����Ϊ��ʹ��һ��Ҳ������������Ҫ��status = 0ʱ�ӵ�һ��֮ǰ��ʼ��Ҳ��pos[0] = 0;
               ���ܵ���-1����Ϊ -1�Ѿ��������ж��Ƿ��Ѿ���¼��״̬�����ڴˣ���Ϊ0λ�ñ�ʾ��һ���ַ�֮ǰ��
               ���Ե�1���ַ�Ҳ������0λ����ʵ��λ��1�����Ժ����¼λ��ʱ��Ҫ����ƫ��1.

               ������ʹ�� -2����ʾδ��¼״̬��-1��ʾ��һ���ַ�ǰ��λ�ã�������¼λ�þͲ���Ҫƫ���ˡ� findTheLongestSubstring2
            */
        }

        return ans;
    }

    int findTheLongestSubstring2(string s) {
        int status = 0, ans = 0;
        vector<int> pos(32, -2);
        pos[0] = -1;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'a')
                status ^= 1 << 0;
            else if (c == 'e')
                status ^= 1 << 1;
            else if (c == 'i')
                status ^= 1 << 2;
            else if (c == 'o')
                status ^= 1 << 3;
            else if (c == 'u')
                status ^= 1 << 4;

            if (pos[status] != -2)
                ans = max(ans, i - pos[status]);
            else
                pos[status] = i;
            /*               
               ������ʹ�� -2����ʾδ��¼״̬��-1��ʾ��һ���ַ�ǰ��λ�ã�������¼λ�þͲ���Ҫƫ���ˡ�
            */
        }

        return ans;
    }
};

// ���沿�ֿ�������������


// ���Կ�ܱر�
string generateTestData() {
    return "leetcodeisgreat";
}

void run(Solution so) {
    auto testData = generateTestData();
    auto ret = so.findTheLongestSubstring(testData);
    ret = ret;
}