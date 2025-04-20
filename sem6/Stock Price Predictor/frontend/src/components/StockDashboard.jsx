import React, { useState, useEffect } from 'react';
import { LineChart, Line, AreaChart, Area, XAxis, YAxis, CartesianGrid, Tooltip, Legend, ResponsiveContainer, BarChart, Bar } from 'recharts';
import { TrendingUp, TrendingDown, Activity, Calendar, Search, Settings, Info, Bell, User, Menu, X, ChevronDown, DollarSign, PieChart, Clock } from 'lucide-react';

export default function StockDashboard() {
  const [selectedStock, setSelectedStock] = useState('RELIANCE');
  const [selectedTimeframe, setSelectedTimeframe] = useState('1Y');
  const [stockData, setStockData] = useState([]);
  const [marketData, setMarketData] = useState([]);
  const [predictions, setPredictions] = useState([]);
  const [performance, setPerformance] = useState([]);
  const [loading, setLoading] = useState(true);
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

  useEffect(() => {
    fetchData();
  }, [selectedStock, selectedTimeframe]);

  const fetchData = async () => {
    try {
      setLoading(true);
      setError(null);

      // Sample data for development
      const sampleStockData = [
        { date: '2024-01-01', open: 1500.0, high: 1520.0, low: 1480.0, close: 1510.0, volume: 1000000 },
        { date: '2024-01-02', open: 1510.0, high: 1530.0, low: 1490.0, close: 1520.0, volume: 1200000 },
        { date: '2024-01-03', open: 1520.0, high: 1540.0, low: 1500.0, close: 1530.0, volume: 1100000 },
      ];

      const sampleMarketData = [];

      const samplePredictions = [
        { symbol: 'RELIANCE', current_price: 2800.0, prediction1d: 2820.0, prediction1w: 2850.0, accuracy: 85 },
        { symbol: 'TCS', current_price: 3500.0, prediction1d: 3520.0, prediction1w: 3550.0, accuracy: 90 },
      ];

      const samplePerformance = [
        { name: '1D', actual: 1.2, predicted: 1.0 },
        { name: '1W', actual: 2.4, predicted: 2.1 },
        { name: '1M', actual: 5.7, predicted: 5.2 },
      ];

      try {
        // Try to fetch real data first
        const stockResponse = await fetch(`http://localhost:5000/api/stock-data?symbol=${selectedStock}&timeframe=${selectedTimeframe}`);
        if (!stockResponse.ok) throw new Error('Backend server not available');
        const stockData = await stockResponse.json();
        setStockData(stockData);

        const marketResponse = await fetch('http://localhost:5000/api/market-data');
        if (!marketResponse.ok) throw new Error('Backend server not available');
        const marketData = await marketResponse.json();
        setMarketData(marketData);

        const predictionsResponse = await fetch(`http://localhost:5000/api/predictions?symbols=${selectedStock}`);
        if (!predictionsResponse.ok) throw new Error('Backend server not available');
        const predictions = await predictionsResponse.json();
        setPredictions(predictions);

        const performanceResponse = await fetch(`http://localhost:5000/api/performance?symbol=${selectedStock}`);
        if (!performanceResponse.ok) throw new Error('Backend server not available');
        const performance = await performanceResponse.json();
        setPerformance(performance);

      } catch (err) {
        // If backend is not available, use sample data
        console.log('Using sample data:', err.message);
        setStockData(sampleStockData);
        setMarketData(sampleMarketData);
        setPredictions(samplePredictions);
        setPerformance(samplePerformance);
      }

    } catch (err) {
      setError('Error loading data. Please try again later.');
      console.error('Error:', err);
    } finally {
      setLoading(false);
    }
  };

  if (loading) {
    return (
      <div className="flex items-center justify-center h-screen">
        <div className="animate-spin rounded-full h-12 w-12 border-t-2 border-b-2 border-indigo-600"></div>
      </div>
    );
  }

  if (error) {
    return (
      <div className="flex items-center justify-center h-screen">
        <div className="text-red-600">{error}</div>
      </div>
    );
  }

  return (
    <div className="flex h-screen bg-gray-50 text-gray-800">
      {/* Main Content */}
      <div className="flex-1 flex flex-col overflow-hidden">
        {/* Top navbar */}
        <header className="bg-white border-b border-gray-200">
          <div className="flex items-center justify-between p-4">
            <div className="flex items-center">
              <h1 className="text-xl font-bold text-indigo-600">StockSense AI</h1>
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
              <button className="p-2 text-gray-500 hover:text-gray-600 hover:bg-gray-100 rounded-full transition-colors">
                <Bell size={20} />
              </button>
            </div>
          </div>
        </header>
        
        {/* Main content body */}
        <main className="flex-1 overflow-y-auto p-4 md:p-6">
          <div className="max-w-7xl mx-auto">
            {/* Header and quick stats */}
            <div className="mb-6">
              <h2 className="text-2xl font-bold mb-4">Stock Dashboard</h2>
              
              {marketData.length > 0 ? (
                <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-4">
                  {marketData.map((market, index) => (
                    <div key={index} className="bg-white p-4 rounded-xl shadow-sm border border-gray-200 hover:shadow-md transition-shadow">
                      <div className="flex justify-between items-center">
                        <div>
                          <p className="text-sm text-gray-500">{market.name}</p>
                          <p className="text-xl font-semibold">₹{market.value}</p>
                        </div>
                        <div className={`${market.trend === 'up' ? 'text-green-500' : 'text-red-500'} flex items-center`}>
                          {market.trend === 'up' ? <TrendingUp size={20} /> : <TrendingDown size={20} />}
                          <span className="ml-1 font-medium">{market.change}</span>
                        </div>
                      </div>
                    </div>
                  ))}
                </div>
              ) : null}
            </div>
            
            {/* Main chart */}
            <div className="bg-white p-4 md:p-6 rounded-xl shadow-sm border border-gray-200 mb-6 hover:shadow-md transition-shadow">
              <div className="flex flex-col md:flex-row md:items-center md:justify-between mb-6">
                <div>
                  <h3 className="text-lg font-semibold">Stock Performance & Prediction</h3>
                  <div className="flex items-center mt-1">
                    <span className="font-medium text-2xl mr-2">₹{stockData[stockData.length - 1]?.close || 0}</span>
                    <span className="px-2 py-1 text-sm font-medium text-green-800 bg-green-100 rounded-full">
                      {((stockData[stockData.length - 1]?.close - stockData[0]?.close) / stockData[0]?.close * 100).toFixed(2)}%
                    </span>
                  </div>
                </div>
                
                <div className="flex mt-4 md:mt-0 space-x-4">
                  <div>
                    <select 
                      value={selectedStock}
                      onChange={(e) => setSelectedStock(e.target.value)}
                      className="px-3 py-2 border border-gray-300 rounded-lg focus:outline-none focus:ring-2 focus:ring-indigo-500"
                    >
                      <option value="RELIANCE">RELIANCE</option>
                      <option value="TCS">TCS</option>
                      <option value="HDFCBANK">HDFCBANK</option>
                      <option value="INFY">INFY</option>
                      <option value="HINDUNILVR">HINDUNILVR</option>
                    </select>
                  </div>
                  
                  <div className="flex border border-gray-300 rounded-lg overflow-hidden">
                    {['1D', '1W', '1M', '3M', '6M', '1Y'].map(timeframe => (
                      <button
                        key={timeframe}
                        className={`px-3 py-2 text-sm ${selectedTimeframe === timeframe ? 'bg-indigo-600 text-white' : 'bg-white text-gray-700 hover:bg-gray-100'} transition-colors`}
                        onClick={() => setSelectedTimeframe(timeframe)}
                      >
                        {timeframe}
                      </button>
                    ))}
                  </div>
                </div>
              </div>
              
              {/* Chart component */}
              <div className="h-72 md:h-96">
                <ResponsiveContainer width="100%" height="100%">
                  <AreaChart
                    data={stockData}
                    margin={{top: 10, right: 10, left: 0, bottom: 0}}
                  >
                    <defs>
                      <linearGradient id="colorPrice" x1="0" y1="0" x2="0" y2="1">
                        <stop offset="5%" stopColor={colors.chartLine} stopOpacity={0.1}/>
                        <stop offset="95%" stopColor={colors.chartLine} stopOpacity={0}/>
                      </linearGradient>
                    </defs>
                    <CartesianGrid strokeDasharray="3 3" vertical={false} />
                    <XAxis dataKey="date" tick={{fontSize: 12}} />
                    <YAxis 
                      domain={['auto', 'auto']}
                      tick={{fontSize: 12}}
                      tickFormatter={(value) => `₹${value}`}
                    />
                    <Tooltip 
                      formatter={(value) => [`₹${value}`, 'Price']} 
                      labelFormatter={(label) => `Date: ${label}`}
                    />
                    <Area 
                      type="monotone" 
                      dataKey="close" 
                      stroke={colors.chartLine} 
                      fillOpacity={1} 
                      fill="url(#colorPrice)" 
                      strokeWidth={2}
                    />
                    <Legend />
                  </AreaChart>
                </ResponsiveContainer>
              </div>
              
              <div className="mt-4 grid grid-cols-2 md:grid-cols-4 gap-4">
                <div className="bg-gray-50 p-3 rounded-lg hover:bg-gray-100 transition-colors">
                  <p className="text-sm text-gray-500">Opening Price</p>
                  <p className="font-medium">₹{stockData[0]?.open || 0}</p>
                </div>
                <div className="bg-gray-50 p-3 rounded-lg hover:bg-gray-100 transition-colors">
                  <p className="text-sm text-gray-500">High</p>
                  <p className="font-medium">₹{Math.max(...stockData.map(d => d.high)) || 0}</p>
                </div>
                <div className="bg-gray-50 p-3 rounded-lg hover:bg-gray-100 transition-colors">
                  <p className="text-sm text-gray-500">Low</p>
                  <p className="font-medium">₹{Math.min(...stockData.map(d => d.low)) || 0}</p>
                </div>
                <div className="bg-gray-50 p-3 rounded-lg hover:bg-gray-100 transition-colors">
                  <p className="text-sm text-gray-500">Volume</p>
                  <p className="font-medium">{stockData[stockData.length - 1]?.volume || 0}</p>
                </div>
              </div>
            </div>
            
            {/* Split view - predictions & performance */}
            <div className="grid grid-cols-1 lg:grid-cols-2 gap-6 mb-6">
              {/* Prediction Table */}
              <div className="bg-white p-4 md:p-6 rounded-xl shadow-sm border border-gray-200 hover:shadow-md transition-shadow">
                <div className="flex justify-between items-center mb-4">
                  <h3 className="text-lg font-semibold">AI Predictions</h3>
                  <div className="flex items-center text-sm text-gray-500">
                    <Clock size={16} className="mr-1" />
                    <span>Updated 2 hours ago</span>
                  </div>
                </div>
                
                <div className="overflow-x-auto">
                  <table className="w-full table-auto">
                    <thead>
                      <tr className="text-left text-gray-500 border-b">
                        <th className="pb-3 font-medium">Stock</th>
                        <th className="pb-3 font-medium">Current</th>
                        <th className="pb-3 font-medium">Tomorrow</th>
                        <th className="pb-3 font-medium">Next Week</th>
                        <th className="pb-3 font-medium">Accuracy</th>
                      </tr>
                    </thead>
                    <tbody>
                      {predictions.map((prediction) => (
                        <tr key={prediction.symbol} className="border-b border-gray-100 hover:bg-gray-50 transition-colors">
                          <td className="py-3 font-medium">{prediction.symbol}</td>
                          <td className="py-3">₹{prediction.current_price}</td>
                          <td className={`py-3 ${prediction.prediction1d > prediction.current_price ? 'text-green-600' : 'text-red-600'}`}>
                            ₹{prediction.prediction1d}
                          </td>
                          <td className={`py-3 ${prediction.prediction1w > prediction.current_price ? 'text-green-600' : 'text-red-600'}`}>
                            ₹{prediction.prediction1w}
                          </td>
                          <td className="py-3">
                            <div className="w-16 bg-gray-200 rounded-full h-2">
                              <div 
                                className="bg-indigo-600 h-2 rounded-full" 
                                style={{ width: `${prediction.accuracy}%` }}
                              ></div>
                            </div>
                          </td>
                        </tr>
                      ))}
                    </tbody>
                  </table>
                </div>
              </div>
              
              {/* Performance comparison */}
              <div className="bg-white p-4 md:p-6 rounded-xl shadow-sm border border-gray-200 hover:shadow-md transition-shadow">
                <div className="flex justify-between items-center mb-4">
                  <h3 className="text-lg font-semibold">Prediction Performance</h3>
                  <select 
                    value={selectedStock}
                    onChange={(e) => setSelectedStock(e.target.value)}
                    className="px-3 py-2 border border-gray-300 rounded-lg text-sm focus:outline-none focus:ring-2 focus:ring-indigo-500"
                  >
                    <option value="RELIANCE">RELIANCE</option>
                    <option value="TCS">TCS</option>
                    <option value="HDFCBANK">HDFCBANK</option>
                    <option value="INFY">INFY</option>
                    <option value="HINDUNILVR">HINDUNILVR</option>
                  </select>
                </div>
                
                <div className="h-72">
                  <ResponsiveContainer width="100%" height="100%">
                    <BarChart
                      data={performance}
                      margin={{ top: 10, right: 10, left: 10, bottom: 10 }}
                    >
                      <CartesianGrid strokeDasharray="3 3" vertical={false} />
                      <XAxis dataKey="name" />
                      <YAxis 
                        tickFormatter={(value) => `${value}%`} 
                        domain={[-5, 35]}
                      />
                      <Tooltip 
                        formatter={(value) => [`${value}%`, '']} 
                        cursor={{ fillOpacity: 0.2 }}
                      />
                      <Legend />
                      <Bar dataKey="actual" fill={colors.actual} name="Actual" radius={[4, 4, 0, 0]} />
                      <Bar dataKey="predicted" fill={colors.predicted} name="Predicted" radius={[4, 4, 0, 0]} />
                    </BarChart>
                  </ResponsiveContainer>
                </div>
                
                <div className="flex justify-between mt-4 px-4 text-sm">
                  <div className="text-center">
                    <p className="text-gray-500">Prediction Accuracy</p>
                    <p className="font-semibold text-lg">93.8%</p>
                  </div>
                  <div className="text-center">
                    <p className="text-gray-500">Average Deviation</p>
                    <p className="font-semibold text-lg">±0.74%</p>
                  </div>
                  <div className="text-center">
                    <p className="text-gray-500">Success Rate</p>
                    <p className="font-semibold text-lg">91.2%</p>
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