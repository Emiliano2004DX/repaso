Sesion global("global");

int main() {
    Sesion a("a");

    {
        Sesion b("b");
        Sesion c("c", 2);
    }

    std::cout << "--- medio ---\n";

    Sesion d;
}