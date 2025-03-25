#include <mpc-rbt-solution/Sender.hpp>

void Sender::Node::run()
{
  while (errno != EINTR) {
    if ((std::chrono::steady_clock::now() - timer_tick) < timer_period) continue;
    timer_tick = std::chrono::steady_clock::now();

    callback();
  }
}



void Sender::Node::onDataTimerTick()
{
// Naplnění zprávy náhodnými daty
  data.x = rand() % 100;
  data.y = rand() % 100;
  data.z = rand() % 100;

  // Nastavení časového razítka
  data.timestamp =
    static_cast<uint64_t>(std::chrono::system_clock::now().time_since_epoch().count());

  // Vytvoření rámce pro odeslání
  Socket::IPFrame frame{
    .port = config.remotePort,
    .address = config.remoteAddress,
  };

  

  // Serializace dat do JSON
  Utils::Message::serialize(frame,data);
  send(frame);
  RCLCPP_INFO(logger, "Sending data: %s:%d", frame.address.c_str(), frame.port);

  RCLCPP_INFO(logger, "\n\tstamp: %ld",
            data.timestamp);

}
