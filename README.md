# Trading Platform

A C++ console-based trading platform simulation that allows users to buy and sell stocks, manage their portfolio, and track transactions in real-time.

## 📋 Features

- **User Management**: Create users with unique IDs and manage balances
- **Stock Market**: Pre-configured with popular stocks (AAPL, NDX, NVDA, SPX)
- **Trading System**: Buy and sell stocks with real-time price calculations
- **Transaction History**: Track all buy/sell operations with timestamps
- **Portfolio Display**: View user balance and transaction history
- **Money Management**: Deposit and withdraw funds

## 🏗️ Architecture

The project follows an object-oriented design with these main classes:

### Core Classes

- **User**: Represents a trader with balance and transaction history
- **Item**: Represents a stock with name and current price
- **Market**: Manages available stocks and facilitates trading
- **Transaction**: Records buy/sell operations with timestamps

### Key Relationships

- Market contains multiple Items (stocks)
- User contains multiple Transactions
- Transactions reference both User and Item
- Market handles all trading operations between Users and Items

## 🚀 Getting Started

### Prerequisites

- C++17 compatible compiler
- CMake (optional)
- libcurl (for future API integration)

### Installation

1. Clone the repository:
```bash
git clone <https://github.com/BartoliniBartlomiej/Trading-App>
```

2. Compile the project:
```bash
g++ -std=c++17 main.cpp market.cpp user.cpp transaction.cpp item.cpp -o trading_app
```

3. Run the application:
```bash
./trading_app
```

## 🎮 Usage

### Main Menu Options

1. **Display User Info**: Show current balance and transaction history
2. **Display Market**: View available stocks and their current prices
3. **Make Trade**: Execute buy/sell operations
4. **Add Money**: Deposit funds into user account
5. **Exit**: Quit the application

### Trading Process

1. Select from available stocks (AAPL, NDX, NVDA, SPX)
2. Choose buy or sell operation
3. Specify quantity in shares or dollar amount
4. Confirm transaction
5. View updated portfolio and transaction history

## 📊 Sample Stocks

The platform comes pre-loaded with these popular stocks:

| Symbol | Name | Initial Price |
|--------|------|---------------|
| AAPL   | Apple Inc. | $250.59 |
| NDX    | NASDAQ-100 | $24,626.25 |
| NVDA   | NVIDIA Corp. | $176.76 |
| SPX    | S&P 500 Index | $6,664.37 |

## 🔧 Technical Details

### Design Patterns

- **Singleton-like**: Market acts as central trading hub
- **Observer**: Potential for real-time price updates
- **Factory**: Transaction creation pattern

### Memory Management

- Uses smart pointers for safe memory handling
- Transaction objects are dynamically allocated
- Proper cleanup mechanisms in place

### Extensibility

The architecture supports easy addition of:
- New stock types
- Additional user features
- Real-time API integration
- Multiple user support
- Advanced trading strategies

## 🌟 Future Enhancements

- [ ] Real-time price updates via Alpha Vantage API
- [ ] Multiple user support with authentication
- [ ] Portfolio performance analytics
- [ ] Historical data tracking
- [ ] Limit orders and advanced trading options
- [ ] Graphical user interface
- [ ] Database persistence
- [ ] Risk management tools

## 🛠️ Development

### Project Structure

```
trading-platform/
├── main.cpp          # Application entry point
├── market.h/cpp      # Market management
├── user.h/cpp        # User entity
├── item.h/cpp        # Stock item representation
├── transaction.h/cpp # Transaction handling
└── README.md         # Project documentation


### Building with CMake

```cmake
cmake_minimum_required(VERSION 3.12)
project(TradingPlatform)

set(CMAKE_CXX_STANDARD 17)

add_executable(app
    main.cpp
    market.cpp
    user.cpp
    transaction.cpp
    item.cpp
)

target_link_libraries(trading_app ${CURL_LIBRARIES})
```

## 📝 License

This project is for educational purposes. Feel free to use and modify as needed.

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## 📞 Support

For questions or support, please open an issue in the GitHub repository.

---

**Note**: This is a simulation platform. All stock prices are fictional and for demonstration purposes only.
