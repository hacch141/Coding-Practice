// 1603. Design Parking System

class ParkingSystem {
public: vector<int> count;
public:
    ParkingSystem(int big, int medium, int small) {
        count = {big, medium, small};
    }
    
    bool addCar(int carType) {
        return count[carType-1]-- > 0;
    }
};
