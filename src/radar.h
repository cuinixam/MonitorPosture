class Radar {
   public:
      Radar();
      int getDistance(void);
      
   private:
      long time_filt_prev;
      
      void setup(void);
      long filterLowPass(long value, long prev_value);
};