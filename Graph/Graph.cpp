#include <iostream>
#include <matplot/matplot.h>
#include <string>
#include <vector>
#include <fstream>

struct give_me_arrays
{
    std::vector<double> x;
    std::vector<double> y;
};

give_me_arrays return_dataPoints(std::string file_name)
{
    int counter = 0;
    give_me_arrays XY;

    std::vector<double> x;
    std::vector<double> y;

    std::string yr, avg;

    std::ifstream my_csv;
    my_csv.open(file_name);


    if (my_csv.is_open())
    {
        while (!my_csv.eof())
        {
            getline(my_csv, yr, ',');
            XY.x.push_back(stof(yr));

            getline(my_csv, avg, '\n');
            XY.y.push_back(stof(avg));
        }

        my_csv.close();
        std::cout << "[INFO] Closing File";
    }

    else
    {
        std::cout << "Error while opening file\n";
    }

    return XY;
}

int main()
{
    int choice;

    give_me_arrays arrays;

    std::string file_pop = "Dataset\\Population.csv";
    std::string file_life_exp = "Dataset\\Japan_LE.csv";
    std::string file_price_vs_area = "Dataset\\Price_Area.csv";
    std::string file_salary = "Dataset\\Salary_Data.csv";
    std::string file_pak_unemployment = "Dataset\\Pak_unemployment.csv";


    std::cout
        << "<1> Pakistan Graph " << std::endl
        << "<2> Japans's Graph " << std::endl
        << "<3> Land Price Graph" << std::endl
        << "<4> Salary Graph" << std::endl
        << "<5> Unepmloyment Graph" << std::endl;
    std::cout << "[INFO] Enter Which Graph you want see: ";
    std::cin >> choice;

    if (choice == 1)
    {
        //population graph
        std::vector<double> k;
        int j = 0;
        arrays = return_dataPoints(file_pop);
        for (int i = 0; i < arrays.y.size(); i++)
        {
            j = (arrays.y[i]) / 1000000.0;
            k.push_back(j);
        }
        matplot::plot(arrays.x, k)->line_width(3).color("cyan");

        matplot::grid(matplot::on);
        matplot::box(matplot::on);
        matplot::xlabel("YEAR");
        matplot::ylabel("Population (Million)");
        matplot::title("Pakistan's Population Graph");
        //matplot::save("pak-population1.png");
        std::cout << "[INFO] Done Saving Graph Of Pakistan's Population";
        matplot::show();

    }

    else if (choice == 2)
    {

        // japan Life expectancy
        arrays = return_dataPoints(file_life_exp);
        matplot::plot(arrays.x, arrays.y)->line_width(3).color("red");

        matplot::grid(matplot::on);
        matplot::box(matplot::on);
        matplot::xlabel("YEAR");
        matplot::ylabel("life lived");
        matplot::title("Japan's Life Expectancy Graph");
        //matplot::save("Japan_life_exp.png");
        std::cout << "[INFO] Done Saving Graph Of Japan's Life Expectancy";
        matplot::show();

    }

    else if (choice == 3)
    {
        std::vector<double> m;
        int q = 0;
        // House price prediction 
        arrays = return_dataPoints(file_price_vs_area);
        for (int h = 0; h < arrays.y.size(); h++)
        {
            q = (arrays.y[h]) / 10000.0;
            m.push_back(q);
        }
        matplot::scatter(arrays.x, m)->line_width(3).color("red");

        matplot::grid(matplot::on);
        matplot::box(matplot::on);
        matplot::xlabel("AREA (sq foot)");
        matplot::ylabel("Price ( $Grands )");
        matplot::title("House price change w.r.t Area Graph");
        //matplot::save("house_price_wrt_area.png");
        std::cout << "[INFO] Done Saving Graph Of House Prediction";
        matplot::show();
    }

    else if (choice == 4)
    {
        // Salary prediction 
        arrays = return_dataPoints(file_salary);
        matplot::plot(arrays.x, arrays.y)->line_width(3).color("red");

        matplot::grid(matplot::on);
        matplot::box(matplot::on);
        matplot::xlabel("Year of Experience");
        matplot::ylabel("Salary ( $ )");
        matplot::title("Salary change w.r.t Year Experience Graph");
        //matplot::save("salary_wrt_year_experience.png");
        std::cout << "[INFO] Done Saving Graph Of  Prediction";
        matplot::show();
    }

    else if (choice == 5)
    {
        // Salary prediction 
        arrays = return_dataPoints(file_pak_unemployment);
        matplot::plot(arrays.x, arrays.y)->line_width(3).color("red");

        matplot::grid(matplot::on);
        matplot::box(matplot::on);
        matplot::xlabel("Year of Pakistan");
        matplot::ylabel("Unemployment Rate");
        matplot::title("Pakistan's Unemployment Rate Graph");
        //matplot::save("pak_unemployment_graph.png");
        std::cout << "[INFO] Done Saving Graph Of  Prediction";
        matplot::show();
    }

    else
    {
        std::cout << "[INFO] INVALID CHOICE NO SUCH GRAPH'S  Exists";
    }

    return 0;
}