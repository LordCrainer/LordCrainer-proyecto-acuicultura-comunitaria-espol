struct IMeasurement
{
    byte pool_id;
    const char *device_id;
    IParams *params;
    const char *created_at;
    const char *status;
};