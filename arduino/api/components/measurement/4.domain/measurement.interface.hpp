struct IParams
{
    String name;
    float value;
    char alert[3];
};

struct IMeasurement
{
    byte pool_id;
    String device_id;
    IParams params[];
    float created_at;
    char status[3];
};