// Bitwise Basic Operations

int getXOR(int a, int b) {
    // Write Your Code Here
    return (a^b);
}

int getBit(int c, int d) {
    // Write Your Code Here
    return ((d>>c) & 1);
}

int setBit(int e, int f) {
    // Write Your Code Here
    return (f | (1<<e));
}
