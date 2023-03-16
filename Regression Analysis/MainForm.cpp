#include "MainForm.h" // Instead of MainForm use name of your cpp file

int main(array<System::String^>^ args)
{
    System::Windows::Forms::Application::EnableVisualStyles();
    System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
    Forms::MainForm form; // Instead of MainForm use name of your cpp file and instead of Forms use the name of your Project
    System::Windows::Forms::Application::Run(% form);
    return 0;
}
