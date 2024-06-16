import paho.mqtt.client as mqtt

# The callback for when the client receives a CONNACK response from the server.


def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe("home/sensors/temperature")
    client.subscribe("home/sensors/humidity")
    client.subscribe("home/sensors/light")

# The callback for when a PUBLISH message is received from the server.


def on_message(client, userdata, msg):
    print(f"Received message '{msg.payload.decode()}' on topic '{
          msg.topic}' with QoS {msg.qos}")


def main():
    client = mqtt.Client()
    client.on_connect = on_connect
    client.on_message = on_message

    broker_address = "192.168.31.64"  # Update with your broker's IP address
    broker_port = 1883
    client.connect(broker_address, broker_port, 60)

    client.loop_forever()


if __name__ == "__main__":
    main()
