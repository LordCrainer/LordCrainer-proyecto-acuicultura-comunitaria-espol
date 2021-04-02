struct IMeasurement
{
    byte pool_id;
    char device_id[4];
    IParams params[];
    float created_at;
    char status[3];
};