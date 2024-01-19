void setup() {

    Serial.begin(115200);

}

void loop() {
    uint32_t freq = 0;
    freq = getCpuFrequencyMhz();
    Serial.print("CPU Freq = ");
    Serial.print(freq);
    Serial.println(" MHz");
    freq = getXtalFrequencyMhz();
    Serial.print("XTAL Freq = ");
    Serial.print(freq);
    Serial.println(" MHz");
    freq = getApbFrequency();
    Serial.print("APB Freq = ");
    Serial.print(freq);
    Serial.println(" Hz");
    delay(2000);
}