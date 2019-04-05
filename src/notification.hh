#ifndef NOTIFICATION_HH
#define NOTIFICATION_HH

#include <condition_variable>
#include <mutex>
#include <chrono>

namespace Terryn
{

enum class WaitReturn
{
    Timeout,
    Running,
    Done,
    Unknown,
};

class Notification
{
private:
    using clock = std::chrono::steady_clock;
    using duration = clock::duration;
    const duration DEFAULT_TIMEOUT = std::chrono::seconds(1);

    std::condition_variable _cv;
    std::mutex _mutex;

    duration _timeout = DEFAULT_TIMEOUT;
    bool _running = false;
    bool _activator = false;
    bool _doTimeout = false;


public:
    Notification() = default;
    Notification(duration timeout);
    void Start();
    void Stop();
    bool IsRunning() const;
    WaitReturn Wait();
    void Notify();
    bool GetActivator() const;
    //    void Reset();
};

}
#endif // NOTIFICATION_HH
