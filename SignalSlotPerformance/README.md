SignalSlot performance test
===========================

For 100,000 signals, executing time (second)

[emitter thread, sync] Direct call                                 0.007
[emitter thread, sync] Qt DirectConnection                         0.075
[emitter thread, sync] sigslot multi_thread_global                 0.382
[emitter thread, sync] sigslot single_threaded                     0.226
[emitter thread, sync] Boost.Signal2                               2.565

[slot thread, sync] Qt BlockingConnection                          2.047

[slot thread, async] Direct call + Boost.Asio                      0.321
[slot thread, async] Qt QueuedConnection                           0.412
[slot thread, async] sigslot + Boost.Asio                          0.605
[slot thread, async] Boost.Signal2 + Boost.Asio                    3.209


# Note
* [emitter thread, sync], means the slot is executed in the ‘emitter’s thread’, the signal is blocked until the slot returns. 
* [slot thread, async], means the slot is executed in the ‘receiver’s thread’, the signal returns immediately. 
* [slot thread, sync], means the slot is executed in  the ‘receiver’s thread’, the signal is blocked until the slot returns.
