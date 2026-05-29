# <!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Checkout - Parivar Mart</title>
  <meta name="description" content="Securely complete your grocery order at Parivar Mart. Add delivery address and choose payment options.">
  <link rel="icon" type="image/x-icon" href="https://cdn-icons-png.flaticon.com/512/3081/3081840.png">
  
  <!-- Icon & Fonts CDN -->
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.0/css/all.min.css">
  
  <!-- External Stylesheets -->
  <link rel="stylesheet" href="css/style.css">
  <link rel="stylesheet" href="css/responsive.css">
</head>
<body>

  <!-- Sticky Header / Navbar -->
  <header>
    <div class="container flex-between navbar">
      <a href="index.html" class="logo">
        <i class="fa-solid fa-basket-shopping"></i> Parivar <span>Mart</span>
      </a>

      <!-- Simplified indicator for checkout -->
      <div style="font-weight:700; color:var(--primary); font-size:1.1rem; display:flex; align-items:center; gap:8px;">
        <i class="fa-solid fa-shield-halved"></i> 100% Safe Checkout
      </div>

      <!-- Desktop Navigation Actions -->
      <nav class="nav-actions">
        <button class="btn-auth" id="btn-auth-desktop" aria-label="Login or Register">
          <i class="fa-solid fa-user-lock"></i> Login
        </button>
        <button class="btn-cart" id="btn-cart-desktop" style="background-color:transparent; border:1px solid var(--border-dark); color:var(--dark);" aria-label="Open Shopping Cart">
          <i class="fa-solid fa-cart-shopping" style="color:var(--primary);"></i>
          <span id="cart-total-display">Basket</span>
          <span class="cart-count" id="cart-count-header" style="background-color:var(--primary); color:var(--light);">0</span>
        </button>
      </nav>

      <!-- Mobile navigation home shortcut -->
      <a href="index.html" style="font-size:1.2rem; color:var(--dark); display:none;" class="menu-toggle" aria-label="Back to home">
        <i class="fa-solid fa-chevron-left"></i>
      </a>
    </div>
  </header>

  <!-- Checkout Portal Content -->
  <main class="container section-padding" style="padding-top:20px;">
    
    <div style="font-size:0.85rem; color:var(--dark-light); margin-bottom:20px;">
      <a href="products.html" style="color:var(--primary); font-weight:600;"><i class="fa-solid fa-arrow-left"></i> Back to Shopping</a>
    </div>

    <!-- Layout Columns -->
    <div class="checkout-layout">
      
      <!-- Address & Payment Forms -->
      <div>
        
        <!-- Guest Notice Banner (shown if logged out) -->
        <div id="guest-login-alert" style="background-color:var(--accent-light); border:1px solid var(--accent); padding:16px; border-radius:var(--radius-md); margin-bottom:24px; display:flex; align-items:center; gap:12px;">
          <i class="fa-solid fa-circle-info" style="color:var(--accent-hover); font-size:1.4rem;"></i>
          <div style="font-size:0.9rem;">
            You are ordering as a <strong>Guest</strong>. 
            <span style="color:var(--primary); font-weight:700; cursor:pointer;" onclick="AuthManager.openModal('login')">Login / Sign Up</span> to save addresses and track orders.
          </div>
        </div>

        <form id="checkout-address-form">
          
          <!-- Delivery Address Card -->
          <div class="checkout-card">
            <h3><i class="fa-solid fa-house-chimney"></i> Delivery Address</h3>
            
            <div id="auth-required-notice" style="display:none; color:var(--danger); font-size:0.8rem; font-weight:600; margin-top:-10px; margin-bottom:15px;">
              * Creating an account helps remember your delivery address.
            </div>
            
            <div style="display:grid; grid-template-columns:1fr 1fr; gap:16px; margin-bottom:16px;">
              <div>
                <label class="form-label" for="checkout-name">Receiver's Full Name</label>
                <input type="text" id="checkout-name" class="form-input" placeholder="e.g. Ramesh Kumar" required>
              </div>
              <div>
                <label class="form-label" for="checkout-phone">10-Digit Mobile Number</label>
                <input type="tel" id="checkout-phone" class="form-input" placeholder="e.g. 9876543210" pattern="[0-9]{10}" required>
              </div>
            </div>

            <div style="display:grid; grid-template-columns:1fr 2fr; gap:16px; margin-bottom:16px;">
              <div>
                <label class="form-label" for="checkout-house">Flat / House No.</label>
                <input type="text" id="checkout-house" class="form-input" placeholder="e.g. Flat 302" required>
              </div>
              <div>
                <label class="form-label" for="checkout-area">Area / Street / Locality</label>
                <input type="text" id="checkout-area" class="form-input" placeholder="e.g. Sector 62, Landmark Park" required>
              </div>
            </div>

            <div style="display:grid; grid-template-columns:1fr 1fr; gap:16px;">
              <div>
                <label class="form-label" for="checkout-landmark">Landmark (Optional)</label>
                <input type="text" id="checkout-landmark" class="form-input" placeholder="e.g. Near Metro Station">
              </div>
              <div>
                <label class="form-label" for="checkout-pincode">6-Digit Pincode</label>
                <input type="text" id="checkout-pincode" class="form-input" placeholder="e.g. 201301" pattern="[0-9]{6}" required>
              </div>
            </div>
          </div>

          <!-- Payment Options Card -->
          <div class="checkout-card">
            <h3><i class="fa-solid fa-credit-card"></i> Select Payment Method</h3>
            
            <div class="payment-options-grid">
              <!-- Cash On Delivery -->
              <div class="payment-option-card active" data-method="cod">
                <i class="fa-solid fa-hand-holding-dollar"></i>
                <span>Cash on Delivery</span>
              </div>
              <!-- UPI Payments -->
              <div class="payment-option-card" data-method="upi">
                <i class="fa-solid fa-mobile-screen-button"></i>
                <span>UPI (GPay/Paytm)</span>
              </div>
              <!-- Credit/Debit Card -->
              <div class="payment-option-card" data-method="card">
                <i class="fa-solid fa-credit-card"></i>
                <span>Credit/Debit Card</span>
              </div>
            </div>
            
            <!-- UPI Details Inputs (Toggled / Info text) -->
            <div style="margin-top:20px; font-size:0.85rem; color:var(--dark-light); line-height:1.4;">
              <span style="font-weight:700; color:var(--dark);">Selected payment mode details:</span>
              <p style="margin-top:4px;">Pay securely at the time of delivery using cash, cards, or scanning QR codes on the delivery agent's scanner.</p>
            </div>
          </div>

          <!-- Submit Order Button -->
          <button type="submit" class="btn-checkout" id="btn-place-order" style="padding:18px; font-size:1.15rem; width:100%; border-radius:var(--radius-lg); margin-top:20px; justify-content:center; gap:8px;">
            Place Order
          </button>
        </form>

      </div>

      <!-- Order Bill Summary Column -->
      <aside>
        <div class="checkout-card" style="position:sticky; top:100px;">
          <h3 style="border-bottom:1px solid var(--border); padding-bottom:12px;"><i class="fa-solid fa-basket-shopping"></i> Order Summary</h3>
          
          <!-- Summary Items Container -->
          <div id="checkout-summary-items" style="max-height:240px; overflow-y:auto; padding:10px 0; border-bottom:1px dashed var(--border-dark); margin-bottom:16px;">
            <!-- Rendered dynamically -->
          </div>

          <!-- Price Breakdown -->
          <div>
            <div class="bill-row">
              <span>Items Subtotal</span>
              <span id="checkout-subtotal">₹0</span>
            </div>
            <div class="bill-row">
              <span>Delivery Fee</span>
              <span id="checkout-delivery">₹0</span>
            </div>
            <div class="bill-row">
              <span>Handling Charge</span>
              <span id="checkout-handling">₹0</span>
            </div>
            <div class="bill-row total" style="margin-bottom:0; padding-bottom:0;">
              <span>To Pay</span>
              <span id="checkout-total">₹0</span>
            </div>
          </div>
        </div>
      </aside>

    </div>

  </main>

  <!-- Footer Section -->
  <footer>
    <div class="container">
      <div class="footer-grid">
        <div class="footer-col footer-about">
          <a href="index.html" class="logo" style="margin-bottom:20px;">
            <i class="fa-solid fa-basket-shopping"></i> Parivar <span>Mart</span>
          </a>
          <p>Your one-stop instant family market delivering groceries and everyday household essentials in minutes.</p>
          <div class="social-links">
            <a href="#"><i class="fa-brands fa-facebook-f"></i></a>
            <a href="#"><i class="fa-brands fa-x-twitter"></i></a>
            <a href="#"><i class="fa-brands fa-instagram"></i></a>
            <a href="#"><i class="fa-brands fa-linkedin-in"></i></a>
          </div>
        </div>
        <div class="footer-col">
          <h4>Useful Links</h4>
          <ul class="footer-links">
            <li><a href="index.html">Home</a></li>
            <li><a href="products.html">Product Catalog</a></li>
            <li><a href="products.html?category=Fruits">Fruits Collection</a></li>
            <li><a href="products.html?category=Dairy">Dairy Products</a></li>
          </ul>
        </div>
        <div class="footer-col">
          <h4>Support & Safety</h4>
          <ul class="footer-links">
            <li><a href="#">Help & Support</a></li>
            <li><a href="#">Terms & Conditions</a></li>
            <li><a href="#">Privacy Policy</a></li>
            <li><a href="#">Cancellation Policy</a></li>
          </ul>
        </div>
        <div class="footer-col">
          <h4>Contact Us</h4>
          <ul class="footer-links" style="color:var(--dark-light); font-size:0.9rem; display:flex; flex-direction:column; gap:12px;">
            <li><i class="fa-solid fa-envelope" style="margin-right:8px; color:var(--primary);"></i> support@parivarmart.com</li>
            <li><i class="fa-solid fa-phone" style="margin-right:8px; color:var(--primary);"></i> +91 1800-419-334</li>
            <li><i class="fa-solid fa-house" style="margin-right:8px; color:var(--primary);"></i> Sector 62, Noida, UP, India</li>
          </ul>
        </div>
      </div>
      <div class="footer-bottom">
        &copy; 2026 Parivar Mart. All rights reserved. Created for family grocery solutions.
      </div>
    </div>
  </footer>

  <!-- MOBILE STICKY BOTTOM NAVIGATION BAR -->
  <nav class="mobile-nav-bar" aria-label="Mobile Navigation">
    <div class="mobile-nav-item" data-view="home">
      <i class="fa-solid fa-house"></i>
      <span>Home</span>
    </div>
    <div class="mobile-nav-item" data-view="categories">
      <i class="fa-solid fa-grip"></i>
      <span>Catalog</span>
    </div>
    <div class="mobile-nav-item" data-view="profile" id="btn-auth-mobile">
      <i class="fa-solid fa-user-lock"></i>
      <span>Login</span>
    </div>
    <div class="mobile-nav-item active" data-view="cart" id="btn-cart-mobile">
      <i class="fa-solid fa-cart-shopping"></i>
      <span>Cart</span>
      <span class="mobile-nav-cart-count" id="cart-count-mobile">0</span>
    </div>
  </nav>

  <!-- CART SIDEBAR DRAWER OVERLAY (required for synchronizing desktop header buttons clicks on checkout) -->
  <div class="cart-drawer-overlay" id="cart-drawer-overlay">
    <div class="cart-drawer" role="dialog" aria-modal="true" aria-label="Shopping Cart">
      <div class="cart-drawer-header">
        <h2>My Basket</h2>
        <button class="btn-close-drawer flex-center" id="close-cart-btn" aria-label="Close cart">
          <i class="fa-solid fa-xmark"></i>
        </button>
      </div>
      <div class="cart-items-wrapper" id="cart-items-wrapper">
        <!-- Rendered dynamically -->
      </div>
      <div class="cart-drawer-footer" id="cart-drawer-footer">
        <!-- Rendered dynamically -->
      </div>
    </div>
  </div>

  <!-- AUTH LOGIN MODAL OVERLAY -->
  <div class="modal-overlay" id="login-modal">
    <div class="modal-box" role="dialog" aria-modal="true" aria-labelledby="login-title">
      <button class="modal-close" id="close-login-btn" aria-label="Close modal"><i class="fa-solid fa-xmark"></i></button>
      <h2 class="modal-title" id="login-title">Welcome Back</h2>
      <p class="modal-desc">Login to access your orders, saved addresses, and fast checkouts.</p>
      
      <form id="login-form">
        <div class="form-group">
          <label class="form-label" for="login-email">Email Address</label>
          <input type="email" id="login-email" class="form-input" placeholder="e.g. user@parivar.com" required>
        </div>
        <div class="form-group">
          <label class="form-label" for="login-password">Password</label>
          <input type="password" id="login-password" class="form-input" placeholder="••••••••" required>
        </div>
        <button type="submit" class="btn-form-submit">Login</button>
      </form>
      <div class="modal-footer-link">
        Don't have an account? <span id="switch-to-signup">Sign Up</span>
      </div>
    </div>
  </div>

  <!-- AUTH SIGNUP MODAL OVERLAY -->
  <div class="modal-overlay" id="signup-modal">
    <div class="modal-box" role="dialog" aria-modal="true" aria-labelledby="signup-title">
      <button class="modal-close" id="close-signup-btn" aria-label="Close modal"><i class="fa-solid fa-xmark"></i></button>
      <h2 class="modal-title" id="signup-title">Create Account</h2>
      <p class="modal-desc">Register with Parivar Mart for premium grocery orders and deals.</p>
      
      <form id="signup-form">
        <div class="form-group">
          <label class="form-label" for="signup-name">Full Name</label>
          <input type="text" id="signup-name" class="form-input" placeholder="e.g. Ramesh Kumar" required>
        </div>
        <div class="form-group">
          <label class="form-label" for="signup-email">Email Address</label>
          <input type="email" id="signup-email" class="form-input" placeholder="e.g. ramesh@gmail.com" required>
        </div>
        <div class="form-group">
          <label class="form-label" for="signup-password">Password</label>
          <input type="password" id="signup-password" class="form-input" placeholder="Minimum 6 characters" required minlength="6">
        </div>
        <div class="form-group">
          <label class="form-label" for="signup-confirm-password">Confirm Password</label>
          <input type="password" id="signup-confirm-password" class="form-input" placeholder="Confirm your password" required minlength="6">
        </div>
        <button type="submit" class="btn-form-submit">Sign Up</button>
      </form>
      <div class="modal-footer-link">
        Already have an account? <span id="switch-to-login">Log In</span>
      </div>
    </div>
  </div>

  <!-- FULL-SCREEN SUCCESS MODAL OVERLAY -->
  <div class="success-overlay" id="success-overlay">
    <div class="success-card">
      <div class="success-icon-anim">
        <i class="fa-solid fa-check"></i>
      </div>
      <h2 class="success-title">Order Confirmed!</h2>
      <p class="success-desc">Thank you for shopping at Parivar Mart. Your items are being packed and will arrive shortly.</p>
      
      <div class="success-details">
        <div class="success-details-row">
          <span style="color:var(--dark-light);">Order ID:</span>
          <strong id="success-order-id">PM-742918</strong>
        </div>
        <div class="success-details-row">
          <span style="color:var(--dark-light);">Amount Paid:</span>
          <strong id="success-amount">₹450</strong>
        </div>
        <div class="success-details-row">
          <span style="color:var(--dark-light);">Delivery In:</span>
          <strong id="success-delivery-time" style="color:var(--primary);">15 Mins</strong>
        </div>
        <div class="success-details-row">
          <span style="color:var(--dark-light);">Payment Mode:</span>
          <strong>Pay-on-Delivery (COD)</strong>
        </div>
      </div>

      <button class="btn-success-home" onclick="window.location.href='index.html'">Continue Shopping</button>
    </div>
  </div>

  <!-- Script Declarations -->
  <script src="js/data.js"></script>
  <script src="js/auth.js"></script>
  <script src="js/cart.js"></script>
  <script src="js/products.js"></script>
  <script src="js/checkout.js"></script>
  <script src="js/app.js"></script>
</body>
</html>