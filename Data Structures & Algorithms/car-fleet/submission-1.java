class Car {
    int position;
    double time;

    Car (int position, double time) {
        this.position = position;
        this.time = time;
    }
}

class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        int n = position.length;
        Car[] cars = new Car[n];

        for (int i = 0; i < n; ++i) 
            cars[i] = new Car(position[i], (double)(target - position[i]) / speed[i]);

        Arrays.sort(cars, (a, b) -> Integer.compare(b.position, a.position));

        int fleetCount = 0;
        double lastFleetTime = 0;

        for (Car car : cars) {
            if (car.time <= lastFleetTime)
                continue;

            fleetCount++;
            lastFleetTime = car.time;
        }
        
        return fleetCount;
    }
}