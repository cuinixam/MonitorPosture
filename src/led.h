class Led
{
public:
    unsigned int blink_counter;
    bool blink_status;
    unsigned long timestamp;

public:
    Led(/* args */);
    ~Led();
    void loop_10ms();
    void on();
    void off();
};
