namespace Matrix {

	class Matrix {
		int m_height, m_width;
		std::vector<std::vector<int>> m_matrix;
	public:
		Matrix() = delete;
		Matrix(int h, int w) noexcept :
			m_height(h), m_width(w),
			m_matrix(std::vector<std::vector<int>>(m_height, std::vector<int>(m_width))) {}
		Matrix(int h, int w, const std::vector<std::vector<int>>& mat) noexcept :
			m_height(h), m_width(w), m_matrix(mat) {}

		int getHeight() const { return m_height; }

		Matrix operator+(const Matrix& mat) const {
			Matrix ans(m_height, m_width);
			for (int h = 0; h < m_height; ++h)for (int w = 0; w < m_width; ++w) {
				ans.m_matrix[h][w] = m_matrix[h][w] + mat.m_matrix[h][w];
			}
			return ans;
		}
		Matrix operator*(const Matrix& mat) const {
			Matrix ans(m_height, m_width);
			for (int h = 0; h < m_height; ++h)for (int w = 0; w < m_width; ++w) {
				int sum = 0;
				for (int k = 0; k < m_height; ++k) {
					sum += m_matrix[h][k] * mat.m_matrix[k][w];
				}
				ans.m_matrix[h][w] = sum;
			}
			return ans;
		}

		std::vector<int> operator[](int h) const {
			return m_matrix[h];
		}

		void operator%=(int mod) {
			for (int h = 0; h < m_height; ++h)for (int w = 0; w < m_width; ++w) {
				m_matrix[h][w] %= mod;
			}
		}

		void print() const noexcept {
			for (int h = 0; h < m_height; ++h) {
				for (int w = 0; w < m_width; ++w) {
					std::cout << m_matrix[h][w] << " ";
				}
				std::cout << std::endl;
			}
		}
	};

	Matrix IdentityMatrix(int h) {
		auto mat = std::vector<std::vector<int>>(h, std::vector<int>(h));
		for (int k = 0; k < h; ++k) { mat[k][k] = 1; }
		return Matrix(h, h, mat);
	};

	Matrix pow(const Matrix& mat, int n) {
		auto ans = IdentityMatrix(mat.getHeight());
		auto matP = mat;
		while (n > 0) {
			if (n & 1) {
				ans = ans * matP;
				ans %= MOD;
			}
			n >>= 1;
			matP = matP * matP;
			matP %= MOD;
		}
		return ans;
	}
}
