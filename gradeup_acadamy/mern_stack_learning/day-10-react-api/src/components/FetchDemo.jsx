import { useState, useEffect } from 'react'
import './FetchDemo.css'

const CATEGORIES = [
  'all',
  'beauty',
  'fragrances',
  'furniture',
  'groceries',
]

export default function FetchDemo() {
  // 1. Core Data Fetching States
  const [products, setProducts] = useState([])
  const [loading, setLoading] = useState(true)
  const [error, setError] = useState(null)

  // 2. Filter & Query States
  const [selectedCategory, setSelectedCategory] = useState('all')
  const [searchQuery, setSearchQuery] = useState('')
  const [sortBy, setSortBy] = useState('default') // 'default' | 'price-asc' | 'price-desc' | 'rating-desc'
  const [limit, setLimit] = useState(12)

  // 3. Educational & Debug States
  const [showCode, setShowCode] = useState(false)
  const [simulateError, setSimulateError] = useState(false)
  const [currentUrl, setCurrentUrl] = useState('')
  const [fetchTrigger, setFetchTrigger] = useState(0) // increment to refetch manually

  // Fetch logic with useEffect and AbortController cleanup
  useEffect(() => {

    const fetchProducts = async () => {
      setLoading(true)
      setError(null)

      try {
        let url = ''

        if (simulateError) {
          // Intentional wrong endpoint to demonstrate error handling
          url = 'https://dummyjson.com/invalid-products-endpoint-404'
        } else if (searchQuery.trim()) {
          // DummyJSON search endpoint
          url = `https://dummyjson.com/products/search?q=${encodeURIComponent(
            searchQuery.trim()
          )}&limit=${limit}`
        } else if (selectedCategory !== 'all') {
          // DummyJSON category endpoint
          url = `https://dummyjson.com/products/category/${selectedCategory}?limit=${limit}`
        } else {
          // Default products endpoint
          url = `https://dummyjson.com/products?limit=${limit}`
        }

        setCurrentUrl(url)

        const response = await fetch(url)

        // Note: fetch() does NOT reject on HTTP 404 or 500, so we check response.ok
        if (!response.ok) {
          throw new Error(
            `Failed to fetch products: ${response.status} ${response.statusText}`
          )
        }

        const data = await response.json()
        setProducts(data.products || [])
      } catch (err) {
        // If aborted by user navigating away or typing again, ignore
        if (err.name === 'AbortError') return
        setError(err.message || 'Something went wrong while fetching data.')
      } finally {
        setLoading(false)
      }
    }

    fetchProducts()

    // Cleanup function runs before next effect execution or component unmount
    return () => {
      controller.abort()
    }
  }, [selectedCategory, searchQuery, limit, simulateError, fetchTrigger])

  // Client-side sorting on the fetched product array
  const sortedProducts = [...products].sort((a, b) => {
    if (sortBy === 'price-asc') return a.price - b.price
    if (sortBy === 'price-desc') return b.price - a.price
    if (sortBy === 'rating-desc') return b.rating - a.rating
    return 0
  })

  // Refetch handler
  const handleRefetch = () => {
    setSimulateError(false)
    setFetchTrigger((prev) => prev + 1)
  }

  // Trigger simulated error
  const handleSimulateError = () => {
    setSimulateError(true)
  }

  return (
    <div className="fetch-demo-container">
      {/* Header */}
      <header className="fetch-demo-header">
        <span className="fetch-badge">React Hooks • API Integration</span>
        <h2 className="fetch-title">Fetch API Demonstration</h2>
        <p className="fetch-subtitle">
          Learn how to fetch data in React using the modern JavaScript <code>fetch()</code> API,{' '}
          <code>useEffect</code>, handling Loading, Error, and Success states.
        </p>
        <div className="endpoint-pill">
          <span>API:</span>
          <code>https://dummyjson.com/products</code>
        </div>
      </header>

      {/* Control Panel: Search, Category, Sorting, Actions */}
      <section className="fetch-controls-card">
        <div className="controls-row-top">
          {/* Search Box */}
          <div className="fetch-search-box">
            <svg
              className="fetch-search-icon"
              width="16"
              height="16"
              viewBox="0 0 24 24"
              fill="none"
              stroke="currentColor"
              strokeWidth="2"
            >
              <circle cx="11" cy="11" r="8"></circle>
              <line x1="21" y1="21" x2="16.65" y2="16.65"></line>
            </svg>
            <input
              type="text"
              className="fetch-search-input"
              placeholder="Search products (e.g. perfume, mascara, bed)..."
              value={searchQuery}
              onChange={(e) => {
                setSimulateError(false)
                setSearchQuery(e.target.value)
              }}
            />
          </div>

          {/* Sort Dropdown */}
          <select
            className="fetch-select"
            value={sortBy}
            onChange={(e) => setSortBy(e.target.value)}
            aria-label="Sort products"
          >
            <option value="default">Sort by: Default</option>
            <option value="price-asc">Price: Low to High</option>
            <option value="price-desc">Price: High to Low</option>
            <option value="rating-desc">Rating: Highest First</option>
          </select>

          {/* Limit Dropdown */}
          <select
            className="fetch-select"
            value={limit}
            onChange={(e) => setLimit(Number(e.target.value))}
            aria-label="Limit items per page"
          >
            <option value="6">Show 6 items</option>
            <option value="12">Show 12 items</option>
            <option value="20">Show 20 items</option>
          </select>

          {/* Action Buttons */}
          <div className="fetch-actions">
            <button
              type="button"
              className="btn-refetch"
              onClick={handleRefetch}
              disabled={loading}
              title="Trigger a new fetch request"
            >
              {loading ? 'Fetching...' : '↻ Refetch'}
            </button>

            <button
              type="button"
              className="btn-simulate-error"
              onClick={handleSimulateError}
              title="Test error boundary state"
            >
              ⚠ Test Error
            </button>

            <button
              type="button"
              className="btn-code-toggle"
              onClick={() => setShowCode(!showCode)}
            >
              {showCode ? 'Hide Code' : '&lt;/&gt; View Code'}
            </button>
          </div>
        </div>

        {/* Category Pills */}
        <div className="category-tags">
          <span style={{ fontSize: '0.8rem', color: 'var(--text)', alignSelf: 'center', marginRight: '0.25rem' }}>
            Category:
          </span>
          {CATEGORIES.map((cat) => (
            <button
              key={cat}
              type="button"
              className={`category-tag-btn ${selectedCategory === cat && !searchQuery ? 'active' : ''
                }`}
              onClick={() => {
                setSimulateError(false)
                setSelectedCategory(cat)
                setSearchQuery('')
              }}
            >
              {cat}
            </button>
          ))}
        </div>
      </section>

      {/* Code Explainer Drawer */}
      {showCode && (
        <section className="code-drawer">
          <div className="code-drawer-header">
            <h4>How this Fetch API code works:</h4>
            <span style={{ fontSize: '0.75rem', color: 'var(--accent)', fontWeight: 600 }}>
              React Pattern
            </span>
          </div>
          <pre>
            {`// 1. Define states for Loading, Data, and Error
const [products, setProducts] = useState([]);
const [loading, setLoading] = useState(true);
const [error, setError] = useState(null);

// 2. Trigger fetch inside useEffect
useEffect(() => {
  const controller = new AbortController();

  const loadData = async () => {
    setLoading(true);
    setError(null);
    try {
      const res = await fetch("https://dummyjson.com/products", {
        signal: controller.signal // Cleanup signal
      });

      // Important: Check res.ok because 404/500 does NOT throw automatically
      if (!res.ok) throw new Error(\`HTTP error! status: \${res.status}\`);

      const data = await res.json();
      setProducts(data.products);
    } catch (err) {
      if (err.name !== 'AbortError') {
        setError(err.message);
      }
    } finally {
      setLoading(false);
    }
  };

  loadData();

  // 3. Cleanup on unmount or re-render
  return () => controller.abort();
}, []);`}
          </pre>
        </section>
      )}

      {/* Status Bar */}
      <div className="status-bar">
        <div>
          Status:{' '}
          {loading ? (
            <strong style={{ color: '#0284c7' }}>Loading data...</strong>
          ) : error ? (
            <strong style={{ color: '#ef4444' }}>Error encountered</strong>
          ) : (
            <strong style={{ color: '#10b981' }}>
              Loaded {sortedProducts.length} products
            </strong>
          )}
        </div>
        <div className="active-api-url">
          GET <span>{currentUrl}</span>
        </div>
      </div>

      {/* STATE 1: LOADING (Skeletons) */}
      {loading && (
        <div className="loading-grid">
          {Array.from({ length: limit }).map((_, idx) => (
            <div key={idx} className="skeleton-card">
              <div className="skeleton-img"></div>
              <div className="skeleton-line title"></div>
              <div className="skeleton-line"></div>
              <div className="skeleton-line price"></div>
            </div>
          ))}
        </div>
      )}

      {/* STATE 2: ERROR STATE */}
      {!loading && error && (
        <div className="error-card">
          <svg
            className="error-icon"
            viewBox="0 0 24 24"
            fill="none"
            stroke="currentColor"
            strokeWidth="2"
          >
            <circle cx="12" cy="12" r="10"></circle>
            <line x1="12" y1="8" x2="12" y2="12"></line>
            <line x1="12" y1="16" x2="12.01" y2="16"></line>
          </svg>
          <h3>Failed to Load Products</h3>
          <p className="error-message">{error}</p>
          <div>
            <button type="button" className="btn-retry" onClick={handleRefetch}>
              ↻ Try Again
            </button>
          </div>
        </div>
      )}

      {/* STATE 3: SUCCESS STATE (Products Grid rendered with .map) */}
      {!loading && !error && (
        <div className="products-grid">
          {sortedProducts.length > 0 ? (
            sortedProducts.map((product) => (
              <article key={product.id} className="product-card">
                {/* Product Thumbnail with Badges */}
                <div className="product-thumb-wrap">
                  <img
                    src={product.thumbnail}
                    alt={product.title}
                    className="product-thumb"
                    loading="lazy"
                  />
                  {product.discountPercentage > 0 && (
                    <span className="discount-badge">
                      -{Math.round(product.discountPercentage)}%
                    </span>
                  )}
                  <span className="rating-badge">
                    ★ {product.rating}
                  </span>
                </div>

                {/* Card Body */}
                <div className="product-body">
                  <div className="product-meta-top">
                    <span className="product-category">
                      {product.category}
                    </span>
                    {product.brand && (
                      <span className="product-brand">{product.brand}</span>
                    )}
                  </div>

                  <h3 className="product-title" title={product.title}>
                    {product.title}
                  </h3>

                  <p className="product-desc" title={product.description}>
                    {product.description}
                  </p>

                  <div className="product-footer">
                    <div className="product-price-block">
                      <span className="price-current">
                        ${product.price}
                      </span>
                    </div>

                    <span
                      className={`stock-tag ${product.stock > 10 ? 'in-stock' : 'low-stock'
                        }`}
                    >
                      {product.stock > 10
                        ? `In Stock (${product.stock})`
                        : `Only ${product.stock} left`}
                    </span>
                  </div>
                </div>
              </article>
            ))
          ) : (
            <div className="no-results">
              <h3>No products found</h3>
              <p>No products match your current search or category filter.</p>
              <button
                type="button"
                className="btn-refetch"
                style={{ marginTop: '1rem' }}
                onClick={() => {
                  setSearchQuery('')
                  setSelectedCategory('all')
                }}
              >
                Clear Filters
              </button>
            </div>
          )}
        </div>
      )}
    </div>
  )
}
