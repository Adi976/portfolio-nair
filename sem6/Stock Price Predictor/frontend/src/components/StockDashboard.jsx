import React, { useState } from 'react';
import { LineChart, Line, AreaChart, Area, XAxis, YAxis, CartesianGrid, Tooltip, Legend, ResponsiveContainer, BarChart, Bar } from 'recharts';
import { TrendingUp, TrendingDown, Activity, Calendar, Search, Settings, Info, Bell, User, Menu, X, ChevronDown, DollarSign, PieChart, Clock } from 'lucide-react';

// Sample data
const stockData = [
  { name: 'Jan', RELIANCE: 145.82, TCS: 222.42, HDFCBANK: 1827.36, INFY: 3206.20, prediction: 150.10 },
  { name: 'Feb', RELIANCE: 121.26, TCS: 232.38, HDFCBANK: 2095.89, INFY: 3092.93, prediction: 125.50 },
  { name: 'Mar', RELIANCE: 119.90, TCS: 235.77, HDFCBANK: 2129.78, INFY: 3094.08, prediction: 122.30 },
  { name: 'Apr', RELIANCE: 131.46, TCS: 252.18, HDFCBANK: 2285.88, INFY: 3340.88, prediction: 135.20 },
  { name: 'May', RELIANCE: 124.61, TCS: 249.68, HDFCBANK: 2411.56, INFY: 3223.91, prediction: 128.40 },
  { name: 'Jun', RELIANCE: 139.96, TCS: 265.02, HDFCBANK: 2506.32, INFY: 3415.25, prediction: 145.30 },
  { name: 'Jul', RELIANCE: 145.86, TCS: 284.91, HDFCBANK: 2704.42, INFY: 3331.48, prediction: 150.70 },
  { name: 'Aug', RELIANCE: 151.83, TCS: 301.14, HDFCBANK: 2874.79, INFY: 3199.95, prediction: 157.20 },
  { name: 'Sep', RELIANCE: 141.50, TCS: 284.00, HDFCBANK: 2673.52, INFY: 3285.04, prediction: 146.80 },
  { name: 'Oct', RELIANCE: 149.80, TCS: 331.62, HDFCBANK: 2924.35, INFY: 3372.41, prediction: 155.40 },
  { name: 'Nov', RELIANCE: 165.30, TCS: 337.91, HDFCBANK: 2922.40, INFY: 3504.56, prediction: 170.10 },
  { name: 'Dec', RELIANCE: 177.57, TCS: 336.32, HDFCBANK: 2897.04, INFY: 3334.34, prediction: 183.20 },
];

const performanceData = [
  { name: '1D', actual: -1.2, predicted: -0.8 },
  { name: '1W', actual: 2.4, predicted: 2.1 },
  { name: '1M', actual: 5.7, predicted: 5.2 },
  { name: '3M', actual: 12.3, predicted: 11.5 },
  { name: '6M', actual: 18.7, predicted: 17.9 },
  { name: 'YTD', actual: 24.2, predicted: 23.1 },
  { name: '1Y', actual: 31.5, predicted: 30.2 },
];

const topStocks = [
  { name: 'RELIANCE', price: 177.57, change: 1.23, changePercent: 0.7 },
  { name: 'TCS', price: 336.32, change: -2.43, changePercent: -0.72 },
  { name: 'HDFCBANK', price: 2897.04, change: 15.35, changePercent: 0.53 },
  { name: 'INFY', price: 3334.34, change: -24.15, changePercent: -0.72 },
  { name: 'HINDUNILVR', price: 352.26, change: 8.34, changePercent: 2.42 },
];

export default function StockDashboard() {
  const [selectedStock, setSelectedStock] = useState('RELIANCE');
  const [selectedTimeframe, setSelectedTimeframe] = useState('1Y');
  const [sidebarOpen, setSidebarOpen] = useState(true);
  const [mobileMenuOpen, setMobileMenuOpen] = useState(false);
  const [prediction, setPrediction] = useState(null);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState(null);
  
  // Chart colors
  const colors = {
    positive: '#10b981',
    negative: '#ef4444',
    actual: '#3b82f6',
    predicted: '#8b5cf6',
    chartLine: '#6366f1',
    chartArea: 'rgba(99, 102, 241, 0.1)',
  };

  const handlePrediction = async () => {
    setLoading(true);
    setError(null);
    try {
      const response = await fetch('http://localhost:5000/predict', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({ symbol: selectedStock }),
      });
      
      if (!response.ok) {
        throw new Error('Failed to get prediction');
      }
      
      const data = await response.json();
      setPrediction(data);
    } catch (err) {
      setError(err.message);
    } finally {
      setLoading(false);
    }
  };

  // Filter data based on selected stock and timeframe
  const filteredStockData = stockData.map(item => ({
    name: item.name,
    value: item[selectedStock],
    prediction: item.prediction
  }));

  const filteredPerformanceData = performanceData.find(item => item.name === selectedTimeframe);

  return (
    <div className="flex h-screen bg-gray-50 text-gray-800">
      {/* Desktop Sidebar */}
      <div className={`${sidebarOpen ? 'w-64' : 'w-20'} hidden md:block bg-white border-r border-gray-200 transition-all duration-300`}>
        <div className="flex flex-col h-full">
          <div className="p-4 flex items-center justify-between">
            {sidebarOpen ? (
              <h1 className="text-xl font-bold text-indigo-600">StockSense AI</h1>
            ) : (
              <h1 className="text-xl font-bold text-indigo-600">SS</h1>
            )}
            <button
              onClick={() => setSidebarOpen(!sidebarOpen)}
              className="p-2 rounded-lg hover:bg-gray-100"
            >
              {sidebarOpen ? <X size={20} /> : <Menu size={20} />}
            </button>
          </div>

          {/* Stock Selection */}
          <div className="p-4">
            <div className="relative">
              <select
                value={selectedStock}
                onChange={(e) => setSelectedStock(e.target.value)}
                className="w-full p-2 border border-gray-300 rounded-lg focus:outline-none focus:ring-2 focus:ring-indigo-500"
              >
                {topStocks.map((stock) => (
                  <option key={stock.name} value={stock.name}>
                    {stock.name}
                  </option>
                ))}
              </select>
            </div>
          </div>

          {/* Timeframe Selection */}
          <div className="p-4">
            <div className="relative">
              <select
                value={selectedTimeframe}
                onChange={(e) => setSelectedTimeframe(e.target.value)}
                className="w-full p-2 border border-gray-300 rounded-lg focus:outline-none focus:ring-2 focus:ring-indigo-500"
              >
                {performanceData.map((item) => (
                  <option key={item.name} value={item.name}>
                    {item.name}
                  </option>
                ))}
              </select>
            </div>
          </div>

          {/* Main Chart */}
          <div className="flex-1 p-4">
            <div className="bg-white rounded-lg shadow p-4 h-full">
              <ResponsiveContainer width="100%" height="100%">
                <AreaChart data={filteredStockData}>
                  <defs>
                    <linearGradient id="colorValue" x1="0" y1="0" x2="0" y2="1">
                      <stop offset="5%" stopColor={colors.chartLine} stopOpacity={0.8}/>
                      <stop offset="95%" stopColor={colors.chartLine} stopOpacity={0}/>
                    </linearGradient>
                  </defs>
                  <CartesianGrid strokeDasharray="3 3" />
                  <XAxis dataKey="name" />
                  <YAxis />
                  <Tooltip />
                  <Area
                    type="monotone"
                    dataKey="value"
                    stroke={colors.chartLine}
                    fillOpacity={1}
                    fill="url(#colorValue)"
                  />
                </AreaChart>
              </ResponsiveContainer>
            </div>
          </div>

          {/* Performance Metrics */}
          {filteredPerformanceData && (
            <div className="p-4">
              <div className="bg-white rounded-lg shadow p-4">
                <h3 className="text-lg font-semibold mb-2">Performance</h3>
                <div className="grid grid-cols-2 gap-4">
                  <div>
                    <p className="text-sm text-gray-500">Actual</p>
                    <p className={`text-lg font-semibold ${filteredPerformanceData.actual >= 0 ? 'text-green-600' : 'text-red-600'}`}>
                      {filteredPerformanceData.actual}%
                    </p>
                  </div>
                  <div>
                    <p className="text-sm text-gray-500">Predicted</p>
                    <p className={`text-lg font-semibold ${filteredPerformanceData.predicted >= 0 ? 'text-green-600' : 'text-red-600'}`}>
                      {filteredPerformanceData.predicted}%
                    </p>
                  </div>
                </div>
              </div>
            </div>
          )}

          {/* Prediction Button */}
          <div className="p-4">
            <button
              onClick={handlePrediction}
              disabled={loading}
              className="w-full bg-indigo-600 text-white py-2 px-4 rounded-lg hover:bg-indigo-700 disabled:opacity-50"
            >
              {loading ? 'Predicting...' : 'Get Prediction'}
            </button>
            {error && (
              <p className="mt-2 text-red-600 text-sm">{error}</p>
            )}
            {prediction && (
              <div className="mt-4 p-4 bg-white rounded-lg shadow">
                <h3 className="text-lg font-semibold mb-2">Prediction Result</h3>
                <div className="grid grid-cols-2 gap-4">
                  <div>
                    <p className="text-sm text-gray-500">Current Price</p>
                    <p className="text-lg font-semibold">₹{prediction.current_price.toFixed(2)}</p>
                  </div>
                  <div>
                    <p className="text-sm text-gray-500">Predicted Price</p>
                    <p className="text-lg font-semibold">₹{prediction.next_price.toFixed(2)}</p>
                  </div>
                  <div>
                    <p className="text-sm text-gray-500">Price Change</p>
                    <p className={`text-lg font-semibold ${prediction.price_change >= 0 ? 'text-green-600' : 'text-red-600'}`}>
                      {prediction.price_change.toFixed(2)}%
                    </p>
                  </div>
                  <div>
                    <p className="text-sm text-gray-500">Direction</p>
                    <p className={`text-lg font-semibold ${prediction.direction === 'up' ? 'text-green-600' : 'text-red-600'}`}>
                      {prediction.direction.toUpperCase()}
                    </p>
                  </div>
                </div>
                <div className="mt-4">
                  <p className="text-sm text-gray-500">Model Performance</p>
                  <div className="grid grid-cols-2 gap-4">
                    <div>
                      <p className="text-sm">RMSE: {prediction.model_metrics.rmse.toFixed(4)}</p>
                    </div>
                    <div>
                      <p className="text-sm">Accuracy: {(prediction.model_metrics.accuracy * 100).toFixed(2)}%</p>
                    </div>
                  </div>
                </div>
              </div>
            )}
          </div>
        </div>
      </div>
      
      {/* Mobile menu */}
      <div className={`fixed inset-0 z-50 ${mobileMenuOpen ? 'block' : 'hidden'}`}>
        <div className="absolute inset-0 bg-gray-600 opacity-75" onClick={() => setMobileMenuOpen(false)}></div>
        <div className="absolute inset-y-0 left-0 w-64 bg-white">
          <div className="p-4 flex justify-between items-center border-b border-gray-200">
            <h1 className="text-xl font-bold text-indigo-600">StockSense AI</h1>
            <button onClick={() => setMobileMenuOpen(false)}>
              <X size={24} />
            </button>
          </div>
          <nav className="p-4">
            <ul className="space-y-2">
              <li><a href="#" className="block p-3 text-indigo-600 bg-indigo-50 rounded-lg">Dashboard</a></li>
              <li><a href="#" className="block p-3 text-gray-700 hover:bg-gray-100 rounded-lg">Predictions</a></li>
              <li><a href="#" className="block p-3 text-gray-700 hover:bg-gray-100 rounded-lg">Analytics</a></li>
              <li><a href="#" className="block p-3 text-gray-700 hover:bg-gray-100 rounded-lg">Portfolio</a></li>
              <li><a href="#" className="block p-3 text-gray-700 hover:bg-gray-100 rounded-lg">History</a></li>
              <li><a href="#" className="block p-3 text-gray-700 hover:bg-gray-100 rounded-lg">Settings</a></li>
              <li><a href="#" className="block p-3 text-gray-700 hover:bg-gray-100 rounded-lg">Profile</a></li>
            </ul>
          </nav>
        </div>
      </div>
      
      {/* Main Content */}
      <div className="flex-1 flex flex-col overflow-hidden">
        {/* Top navbar */}
        <header className="bg-white border-b border-gray-200">
          <div className="flex items-center justify-between p-4">
            <div className="flex items-center md:hidden">
              <button onClick={() => setMobileMenuOpen(true)} className="text-gray-500 hover:text-gray-600">
                <Menu size={24} />
              </button>
            </div>
            
            <div className="flex-1 max-w-lg mx-4">
              <div className="relative">
                <Search className="absolute left-3 top-3 text-gray-400" size={20} />
                <input
                  type="text"
                  placeholder="Search for stocks..."
                  className="w-full pl-10 pr-4 py-2 border border-gray-300 rounded-lg focus:outline-none focus:ring-2 focus:ring-indigo-500"
                />
              </div>
            </div>
            
            <div className="flex items-center space-x-4">
              <button className="p-2 text-gray-500 hover:text-gray-600 hover:bg-gray-100 rounded-full">
                <Bell size={20} />
              </button>
              <button className="flex items-center space-x-2 p-2 hover:bg-gray-100 rounded-lg">
                <div className="w-8 h-8 bg-indigo-600 rounded-full flex items-center justify-center text-white font-medium">
                  JD
                </div>
                <span className="hidden md:block">John Doe</span>
              </button>
            </div>
          </div>
        </header>
        
        {/* Main content body */}
        <main className="flex-1 overflow-y-auto p-4 md:p-6">
          <div className="max-w-7xl mx-auto">
            {/* Header and quick stats */}
            <div className="mb-6">
              <h2 className="text-2xl font-bold mb-4">Market Dashboard</h2>
              
              <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-4">
                <div className="bg-white p-4 rounded-xl shadow-sm border border-gray-200">
                  <div className="flex justify-between items-center">
                    <div>
                      <p className="text-sm text-gray-500">S&P 500</p>
                      <p className="text-xl font-semibold">4,185.47</p>
                    </div>
                    <div className="text-green-500 flex items-center">
                      <TrendingUp size={20} />
                      <span className="ml-1 font-medium">1.8%</span>
                    </div>
                  </div>
                </div>
                
                <div className="bg-white p-4 rounded-xl shadow-sm border border-gray-200">
                  <div className="flex justify-between items-center">
                    <div>
                      <p className="text-sm text-gray-500">NASDAQ</p>
                      <p className="text-xl font-semibold">13,748.74</p>
                    </div>
                    <div className="text-green-500 flex items-center">
                      <TrendingUp size={20} />
                      <span className="ml-1 font-medium">2.3%</span>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </main>
      </div>
    </div>
  );
} 