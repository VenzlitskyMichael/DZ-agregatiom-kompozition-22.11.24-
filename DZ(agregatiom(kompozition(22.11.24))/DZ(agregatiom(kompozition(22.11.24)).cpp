#include <iostream>
using namespace std;

class CPU {
    string model;
    double Gghz;
public:
    CPU() = default;
    CPU(const char* mod, double ghz) : model(mod), Gghz(ghz) {}
    void Print() const {
        cout << "Model CPU: " << model << " " << Gghz << " GHz" << endl;
    }
};

class SSD {
    string model;
    double capacity;
public:
    SSD() = default;
    SSD(const char* mod, double cap) : model(mod), capacity(cap) {}
    void Print() const {
        cout << "Model SSD:  " << model << " " << capacity << " GB" << endl;
    }
};

class RAM {
    string model;
    double size;
public:
    RAM() = default;
    RAM(const char* mod, double sz) : model(mod), size(sz) {}
    void Print() const {
        cout << "Model RAM: " << model << " " << size << " GB" << endl;
    }
};

class GPU {
    string model;
    double power;
public:
    GPU() = default;
    GPU(const char* mod, double pow) : model(mod), power(pow) {}
    void Print() const {
        cout << "Model GPU: " << model << " " << power << " Wat" << endl;
    }
};

class MOUSE {
    string model;
    double dpi;
public:
    MOUSE() = default;
    MOUSE(const char* mod, double dpi_value) : model(mod), dpi(dpi_value) {}
    void Print() const {
        cout << "Model Mouse: " << model << " " << dpi << " DPI" << endl;
    }
};

class Laptop {
    CPU cpu;
    SSD ssd;
    RAM ram;
    GPU gpu;
    MOUSE* mouse; 
    int year;
public:
    Laptop(const CPU& c, const SSD& s, const RAM& r, const GPU& g, const char* mMod, double mDPI, int yr)
        : cpu(c), ssd(s), ram(r), gpu(g), year(yr) {
        mouse = new MOUSE(mMod, mDPI);
    }
    void Show() const {
        cout << "Laptop manufactured in " << year << " contains:\n";
        cpu.Print();
        ssd.Print();
        ram.Print();
        gpu.Print();
        mouse->Print();
    }
    ~Laptop() {
        delete mouse;
        cout << "Laptop destroyed\n";
    }
};

int main() {
    CPU cpu("Intel i3", 3.5);
    SSD ssd("Radiance exp", 512);
    RAM ram("Corsair", 16);
    GPU gpu("INVIDIA GEFORCE RTX 4090", 720);

    Laptop* myLaptop = new Laptop(cpu, ssd, ram, gpu, "Asus GALAXY Master", 19400, 2022);
    myLaptop->Show();

    delete myLaptop;

    return 0;
}
