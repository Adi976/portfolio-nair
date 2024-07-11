import React from 'react';
import { users, products, articles } from './data';

const App = () => {
  return (
    <div>
      <h1>Users</h1>
      <ul>
        {users.map(user => (
          <li key={user.id}>
            <strong>{user.name}</strong> - {user.email}, {user.phone}
          </li>
        ))}
      </ul>

      <h1>Products</h1>
      <ul>
        {products.map(product => (
          <li key={product.id}>
            <strong>{product.name}</strong> - ${product.price} <br />
            {product.description} <br />
            Category: {product.category} <br />
            In Stock: {product.stock}
          </li>
        ))}
      </ul>

      <h1>Articles</h1>
      <ul>
        {articles.map(article => (
          <li key={article.id}>
            <strong>{article.title}</strong> by {article.author} <br />
            {article.content.substring(0, 100)}... <br />
            Published on: {article.date}
          </li>
        ))}
      </ul>
    </div>
  );
};

export default App;
