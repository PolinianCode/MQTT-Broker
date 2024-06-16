import unittest
import time
import paho.mqtt.client as mqtt

MQTT_BROKER = "192.168.31.64"
MQTT_PORT = 1883
MQTT_TEST_TOPIC = "home/sensors/temperature"
MQTT_TEST_MESSAGE = "20"

class TestMQTTBroker(unittest.TestCase):

    def setUp(self):
        self.client = mqtt.Client()
        self.client.on_connect = self.on_connect
        self.client.on_message = self.on_message
        self.client.connect(MQTT_BROKER, MQTT_PORT, 60)
        self.client.loop_start()
        self.connected = False
        self.received_message = None

    def tearDown(self):
        self.client.loop_stop()
        self.client.disconnect()

    def on_connect(self, client, userdata, flags, rc):
        if rc == 0:
            self.connected = True
        else:
            self.fail("Connection failed with result code " + str(rc))

    def on_message(self, client, userdata, msg):
        self.received_message = msg.payload.decode()

    def test_connection(self):
        # Test if the client connects successfully
        time.sleep(2)  # Wait for connection setup
        self.assertTrue(self.connected)

    def test_publish_and_subscribe(self):
        # Subscribe to a test topic
        self.client.subscribe(MQTT_TEST_TOPIC)

        # Publish a message to the test topic
        self.client.publish(MQTT_TEST_TOPIC, MQTT_TEST_MESSAGE)

        # Wait for the message to be received
        time.sleep(2)

        # Check if the received message is correct
        self.assertEqual(self.received_message, MQTT_TEST_MESSAGE)

if __name__ == "__main__":
    unittest.main()
