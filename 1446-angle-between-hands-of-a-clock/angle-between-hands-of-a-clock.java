class Solution {
    public double angleClock(int hour, int minutes) {
        double minDegPM = 6;
        double hrDegPM = 0.5;
        double hrDegPH = 30;
        double totalMinRot = minutes * minDegPM;
        double totalHrRot = (hour % 12) * hrDegPH + (minutes * hrDegPM);
        double angle = Math.abs(totalHrRot - totalMinRot);
        if(angle > 180) return (360-angle);
        return angle;
    }
}