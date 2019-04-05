#include "notification.hh"


Terryn::Notification::Notification(duration timeout) :
                                                     _timeout(timeout), _doTimeout(true)
{ }

void Terryn::Notification::Start()
{
    _activator = false;
    _running = true;
}

void Terryn::Notification::Stop()
{
    _activator = false;
    _running = false;
    _cv.notify_all();
}

bool Terryn::Notification::IsRunning() const
{
    return _running;
}

Terryn::WaitReturn Terryn::Notification::Wait()
{
    std::unique_lock<std::mutex> lk(_mutex);

    if(_doTimeout)
    {
        if(_cv.wait_for(lk, _timeout, [this]
                         {
                             return _activator || !_running;
                         }))
        {
            if(_activator)
            {
                _activator = false;
            }
            if(_running)
            {
                return Terryn::WaitReturn::Running;
            }
            else
            {
                return Terryn::WaitReturn::Done;
            }
        }
        else
        {
            return Terryn::WaitReturn::Timeout;
        }
    }
    else
    {
        _cv.wait(lk, [this]
                 {
                     return _activator || !_running;
                 });
        if(_activator)
        {
            _activator = false;
        }
        if(_running)
        {
            return Terryn::WaitReturn::Running;
        }
        else
        {
            return Terryn::WaitReturn::Done;
        }
    }

    /// this should never happen
    return WaitReturn::Unknown;
}

void Terryn::Notification::Notify()
{
    /// return if the notification is not actually running
    if(!_running)
    {
        return;
    }
    _activator = true;
    _cv.notify_one();
}

bool Terryn::Notification::GetActivator() const
{
    return _activator;
}

