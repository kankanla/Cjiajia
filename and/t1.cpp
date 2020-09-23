#include <fstream>
#include <random>

int main()
{
  // メルセンヌ・ツイスター法による擬似乱数生成器を、
  // ハードウェア乱数をシードにして初期化
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());

  // 一様実数分布
  // [-1.0, 1.0)の値の範囲で、等確率に実数を生成する
  std::uniform_real_distribution<> dist1(-1.0, 1.0);

  // 正規分布
  // 平均1.0、標準偏差0.5で分布させる
  std::normal_distribution<> dist2(1.0, 0.5);

  std::ofstream file("random.tsv");
  for (size_t i = 0; i < 1000 * 1000; ++i) {
    // 各分布法に基いて乱数を生成
    double r1 = dist1(engine);
    double r2 = dist2(engine);

    file << r1 << "\t" << r2 << "\n";
  }
}