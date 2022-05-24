using namespace std;

long long ost(int x, int y) {
    while (y != 0) {
        int z = x % y;
        x = y;
        y = z;

    }
    return x;
}

long long solution(int w, int h) {

    long long answer = 0;

    long long enl = (long long)w + (long long)h - ost(w, h);
    long long Gob = (long long)w * (long long)h;

    answer = Gob - enl;

    return answer;
}