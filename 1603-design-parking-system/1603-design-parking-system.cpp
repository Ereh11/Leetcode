class ParkingSystem {
private:
    int big = 0, medium = 0, small = 0;
public:
    ParkingSystem(int b, int m, int s) {
        big = b;
        medium = m;
        small = s;
    }
    
    bool addCar(int carType) 
    {
        if(carType == 1 && big){
            big--; return 1;
        }
        else if(carType == 2 && medium){
            medium--; return 1;
        }
        else if(carType == 3 && small){
            small--; return 1;
        } 
        else return 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */