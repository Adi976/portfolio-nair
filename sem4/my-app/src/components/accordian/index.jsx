import React from 'react';
import { users, products, articles } from '../../data';

const App = () => {
  return (
    <div>
      <h1>Users</h1>
      <ul>
        {users.map(user => (
          <li key={user.id}>
            {user.name} - {user.email}
          </li>
        ))}
      </ul>

      <h1>Products</h1>
      <ul>
        {products.map(product => (
          <li key={product.id}>
            {product.name} - ${product.price}
          </li>
        ))}
      </ul>

      <h1>Articles</h1>
      <ul>
        {articles.map(article => (
          <li key={article.id}>
            {article.title} by {article.author} on {article.date}
          </li>
        ))}
      </ul>
    </div>
  );
};

export default App;
