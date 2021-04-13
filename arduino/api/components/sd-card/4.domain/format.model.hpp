String ajustUnitSize(int size)
{
    const float KB = 1024.0;
    const float MB = 1024.0 * 1024.0;
    if (size >= MB)
    {
        return String(size / MB) + "MB";
    }
    if (size >= KB)
    {
        return String(size / KB) + "KB";
    }
    return String(size) + "B";
}