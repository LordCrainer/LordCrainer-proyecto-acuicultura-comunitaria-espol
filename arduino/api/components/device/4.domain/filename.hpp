String setFilename(const char letter[2], byte pool_id, String time, String ext)
{

    return letter + String(pool_id) + "_" + time + "." + ext;
}