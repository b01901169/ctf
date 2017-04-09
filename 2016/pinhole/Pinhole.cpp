



<!DOCTYPE html>
<html lang="en" class="">
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# object: http://ogp.me/ns/object# article: http://ogp.me/ns/article# profile: http://ogp.me/ns/profile#">
    <meta charset='utf-8'>

    <link crossorigin="anonymous" href="https://assets-cdn.github.com/assets/frameworks-355fc5f5dc43030d495ea75b6bc8366695646a7566c13dd6ba2c2d358e1b5383.css" media="all" rel="stylesheet" />
    <link crossorigin="anonymous" href="https://assets-cdn.github.com/assets/github-7fae2d802a203f722465a757a5c1ecdb285d355fdcda038c10a2d20722dcf959.css" media="all" rel="stylesheet" />
    
    
    <link crossorigin="anonymous" href="https://assets-cdn.github.com/assets/site-429acc2fc05149afec2a05196b3100560f117f753931d0afca46da6e1eeafe39.css" media="all" rel="stylesheet" />
    

    <link as="script" href="https://assets-cdn.github.com/assets/frameworks-752d672b75dd3528039ea14e78d5638b9126eeb7de38701f46091862c63d73da.js" rel="preload" />
    
    <link as="script" href="https://assets-cdn.github.com/assets/github-ba6a49a5b72a3b71afb5394ab11a0b1a4d15cdb5877879000bf1bca10c19e310.js" rel="preload" />

    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta http-equiv="Content-Language" content="en">
    <meta name="viewport" content="width=device-width">
    <meta content="origin" name="referrer" />
    
    <title>Pinhole.cpp · GitHub</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub">
    <link rel="fluid-icon" href="https://gist.github.com/fluidicon.png" title="GitHub">
    <link rel="apple-touch-icon" href="/apple-touch-icon.png">
    <link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-57x57.png">
    <link rel="apple-touch-icon" sizes="60x60" href="/apple-touch-icon-60x60.png">
    <link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-72x72.png">
    <link rel="apple-touch-icon" sizes="76x76" href="/apple-touch-icon-76x76.png">
    <link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114x114.png">
    <link rel="apple-touch-icon" sizes="120x120" href="/apple-touch-icon-120x120.png">
    <link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144x144.png">
    <link rel="apple-touch-icon" sizes="152x152" href="/apple-touch-icon-152x152.png">
    <link rel="apple-touch-icon" sizes="180x180" href="/apple-touch-icon-180x180.png">
    <meta property="fb:app_id" content="1401488693436528">

      <meta content="https://avatars3.githubusercontent.com/u/2498406?v=3&amp;s=400" name="twitter:image:src" /><meta content="@github" name="twitter:site" /><meta content="summary" name="twitter:card" /><meta content="Pinhole.cpp" name="twitter:title" /><meta content="" name="twitter:description" />
      <meta content="https://avatars3.githubusercontent.com/u/2498406?v=3&amp;s=400" property="og:image" /><meta content="Gist" property="og:site_name" /><meta content="object" property="og:type" /><meta content="Pinhole.cpp" property="og:title" /><meta content="https://gist.github.com/seanwupi/bf364ed692f059ccc5ef1839212a6834" property="og:url" /><meta content="" property="og:description" />
      <meta name="browser-stats-url" content="https://api.github.com/_private/browser/stats">
    <meta name="browser-errors-url" content="https://api.github.com/_private/browser/errors">
    <link rel="assets" href="https://assets-cdn.github.com/">
    
    <meta name="pjax-timeout" content="1000">
    

    <meta name="msapplication-TileImage" content="/windows-tile.png">
    <meta name="msapplication-TileColor" content="#ffffff">
    <meta name="selected-link" value="gist_code" data-pjax-transient>

    <meta name="google-site-verification" content="KT5gs8h0wvaagLKAVWq8bbeNwnZZK1r1XQysX3xurLU">
<meta name="google-site-verification" content="ZzhVyEFwb7w3e0-uOTltm8Jsck2F5StVihD0exw2fsA">
    <meta name="google-analytics" content="UA-3769691-4">

<meta content="collector.githubapp.com" name="octolytics-host" /><meta content="gist" name="octolytics-app-id" /><meta content="8C70D911:4341:8E0FDE:5768EBF0" name="octolytics-dimension-request_id" />
<meta content="/&lt;user-name&gt;/&lt;gist-id&gt;" data-pjax-transient="true" name="analytics-location" />



  <meta class="js-ga-set" name="dimension1" content="Logged Out">


    <meta content="false" name="octolytics-dimension-public" /><meta content="36731757" name="octolytics-dimension-gist_id" /><meta content="bf364ed692f059ccc5ef1839212a6834" name="octolytics-dimension-gist_name" /><meta content="false" name="octolytics-dimension-anonymous" /><meta content="2498406" name="octolytics-dimension-owner_id" /><meta content="seanwupi" name="octolytics-dimension-owner_login" /><meta content="false" name="octolytics-dimension-forked" />

  <meta class="js-ga-set" name="dimension5" content="secret">
  <meta class="js-ga-set" name="dimension6" content="owned">
  <meta class="js-ga-set" name="dimension7" content="c++">



        <meta name="hostname" content="gist.github.com">
    <meta name="user-login" content="">

        <meta name="expected-hostname" content="gist.github.com">
      <meta name="js-proxy-site-detection-payload" content="YjFlOWMzMjdlZjA5YmFhY2E5ODFmMDBhYzAyN2JkMjA4MzViNGM5NmU3ZGM0MzRjNTVjNTVjZTVkY2EwOTliMHx7InJlbW90ZV9hZGRyZXNzIjoiMTQwLjExMi4yMTcuMTciLCJyZXF1ZXN0X2lkIjoiOEM3MEQ5MTE6NDM0MTo4RTBGREU6NTc2OEVCRjAiLCJ0aW1lc3RhbXAiOjE0NjY0OTM5Mzd9">


      <link rel="mask-icon" href="https://assets-cdn.github.com/pinned-octocat.svg" color="#4078c0">
      <link rel="icon" type="image/x-icon" href="https://assets-cdn.github.com/favicon.ico">

    <meta name="html-safe-nonce" content="fb349930772efdfa0814a0866243dd362d5db32a">
    <meta content="15a27d6c0c3b6078ab4e2eb8b9eae8bf050ffd68" name="form-nonce" />

    <meta http-equiv="x-pjax-version" content="b466760c03426873ff9b6b5cc1735510">
    

        <link href="/seanwupi.atom" rel="alternate" title="atom" type="application/atom+xml">
  <meta content="noindex, follow" name="robots" />
  <link crossorigin="anonymous" href="https://assets-cdn.github.com/assets/gist-713674463b13fef4283a3095245780f0179f1b208dc8ca09f663979b4ff37a3c.css" media="all" rel="stylesheet" />


  </head>


  <body class="logged-out   env-production linux">
    <div id="js-pjax-loader-bar" class="pjax-loader-bar"></div>
    <a href="#start-of-content" tabindex="1" class="accessibility-aid js-skip-to-content">Skip to content</a>

    
    
    



        <div class="header gist-header header-logged-out" role="banner">
  <div class="container clearfix">

    <a href="/" aria-label="Gist Homepage" class="header-logo-wordmark" data-hotkey="g d">
      <svg aria-hidden="true" class="octicon octicon-logo-github" height="28" version="1.1" viewBox="0 0 45 16" width="78"><path d="M18.53 12.03h-.02c.009 0 .015.01.024.011h.006l-.01-.01zm.004.011c-.093.001-.327.05-.574.05-.78 0-1.05-.36-1.05-.83V8.13h1.59c.09 0 .16-.08.16-.19v-1.7c0-.09-.08-.17-.16-.17h-1.59V3.96c0-.08-.05-.13-.14-.13h-2.16c-.09 0-.14.05-.14.13v2.17s-1.09.27-1.16.28c-.08.02-.13.09-.13.17v1.36c0 .11.08.19.17.19h1.11v3.28c0 2.44 1.7 2.69 2.86 2.69.53 0 1.17-.17 1.27-.22.06-.02.09-.09.09-.16v-1.5a.177.177 0 0 0-.146-.18zm23.696-2.2c0-1.81-.73-2.05-1.5-1.97-.6.04-1.08.34-1.08.34v3.52s.49.34 1.22.36c1.03.03 1.36-.34 1.36-2.25zm2.43-.16c0 3.43-1.11 4.41-3.05 4.41-1.64 0-2.52-.83-2.52-.83s-.04.46-.09.52c-.03.06-.08.08-.14.08h-1.48c-.1 0-.19-.08-.19-.17l.02-11.11c0-.09.08-.17.17-.17h2.13c.09 0 .17.08.17.17v3.77s.82-.53 2.02-.53l-.01-.02c1.2 0 2.97.45 2.97 3.88zm-8.72-3.61H33.84c-.11 0-.17.08-.17.19v5.44s-.55.39-1.3.39-.97-.34-.97-1.09V6.25c0-.09-.08-.17-.17-.17h-2.14c-.09 0-.17.08-.17.17v5.11c0 2.2 1.23 2.75 2.92 2.75 1.39 0 2.52-.77 2.52-.77s.05.39.08.45c.02.05.09.09.16.09h1.34c.11 0 .17-.08.17-.17l.02-7.47c0-.09-.08-.17-.19-.17zm-23.7-.01h-2.13c-.09 0-.17.09-.17.2v7.34c0 .2.13.27.3.27h1.92c.2 0 .25-.09.25-.27V6.23c0-.09-.08-.17-.17-.17zm-1.05-3.38c-.77 0-1.38.61-1.38 1.38 0 .77.61 1.38 1.38 1.38.75 0 1.36-.61 1.36-1.38 0-.77-.61-1.38-1.36-1.38zm16.49-.25h-2.11c-.09 0-.17.08-.17.17v4.09h-3.31V2.6c0-.09-.08-.17-.17-.17h-2.13c-.09 0-.17.08-.17.17v11.11c0 .09.09.17.17.17h2.13c.09 0 .17-.08.17-.17V8.96h3.31l-.02 4.75c0 .09.08.17.17.17h2.13c.09 0 .17-.08.17-.17V2.6c0-.09-.08-.17-.17-.17zM8.81 7.35v5.74c0 .04-.01.11-.06.13 0 0-1.25.89-3.31.89-2.49 0-5.44-.78-5.44-5.92S2.58 1.99 5.1 2c2.18 0 3.06.49 3.2.58.04.05.06.09.06.14L7.94 4.5c0 .09-.09.2-.2.17-.36-.11-.9-.33-2.17-.33-1.47 0-3.05.42-3.05 3.73s1.5 3.7 2.58 3.7c.92 0 1.25-.11 1.25-.11v-2.3H4.88c-.11 0-.19-.08-.19-.17V7.35c0-.09.08-.17.19-.17h3.74c.11 0 .19.08.19.17z"></path></svg>
      <svg aria-hidden="true" class="octicon octicon-logo-gist" height="28" version="1.1" viewBox="0 0 25 16" width="40"><path d="M4.7 8.73h2.45v4.02c-.55.27-1.64.34-2.53.34-2.56 0-3.47-2.2-3.47-5.05 0-2.85.91-5.06 3.48-5.06 1.28 0 2.06.23 3.28.73V2.66C7.27 2.33 6.25 2 4.63 2 1.13 2 0 4.69 0 8.03c0 3.34 1.11 6.03 4.63 6.03 1.64 0 2.81-.27 3.59-.64V7.73H4.7v1zm6.39 3.72V6.06h-1.05v6.28c0 1.25.58 1.72 1.72 1.72v-.89c-.48 0-.67-.16-.67-.7v-.02zm.25-8.72c0-.44-.33-.78-.78-.78s-.77.34-.77.78.33.78.77.78.78-.34.78-.78zm4.34 5.69c-1.5-.13-1.78-.48-1.78-1.17 0-.77.33-1.34 1.88-1.34 1.05 0 1.66.16 2.27.36v-.94c-.69-.3-1.52-.39-2.25-.39-2.2 0-2.92 1.2-2.92 2.31 0 1.08.47 1.88 2.73 2.08 1.55.13 1.77.63 1.77 1.34 0 .73-.44 1.42-2.06 1.42-1.11 0-1.86-.19-2.33-.36v.94c.5.2 1.58.39 2.33.39 2.38 0 3.14-1.2 3.14-2.41 0-1.28-.53-2.03-2.75-2.23h-.03zm8.58-2.47v-.86h-2.42v-2.5l-1.08.31v2.11l-1.56.44v.48h1.56v5c0 1.53 1.19 2.13 2.5 2.13.19 0 .52-.02.69-.05v-.89c-.19.03-.41.03-.61.03-.97 0-1.5-.39-1.5-1.34V6.94h2.42v.02-.01z"></path></svg>
</a>
    <div class="site-search js-site-search" role="search">
        <div class="header-search" role="search">

<!-- </textarea> --><!-- '"` --><form accept-charset="UTF-8" action="/search" method="get"><div style="margin:0;padding:0;display:inline"><input name="utf8" type="hidden" value="&#x2713;" /></div>
  <label class="header-search-wrapper form-control js-chromeless-input-container">
    <input type="text"
      class="form-control js-site-search-focus header-search-input"
      data-hotkey="s"
      name="q"
      placeholder="Search…"
      tabindex="1"
      autocorrect="off"
      autocomplete="off"
      autocapitalize="off">
  </label>

</form></div>

    </div>
    <ul class="header-nav left" role="navigation">
      <li class="header-nav-item">
        <a href="/discover" class="header-nav-link" data-ga-click="Header, go to all gists, text:all gists">All gists</a>
      </li>

      <li class="header-nav-item">
        <a href="https://github.com" class="header-nav-link" data-ga-click="Header, go to GitHub, text:GitHub">GitHub</a>
      </li>
    </ul>

      <div class="header-actions" role="navigation">
        <a href="/join?source=header-gist" class="btn btn-primary" data-ga-click="Header, sign up">Sign up for a GitHub account</a>
        <a href="https://gist.github.com/auth/github?return_to=gist" class="btn" data-ga-click="Header, sign in">Sign in</a>
      </div>

  </div>
</div>




    <div id="start-of-content" class="accessibility-aid"></div>

      <div id="js-flash-container">
</div>


    <div role="main" class="main-content">
      
  <div itemscope itemtype="http://schema.org/Code">
    <div id="gist-pjax-container" class="gist-content-wrapper" data-pjax-container>
          <div class="gist-detail-intro gist-banner">
      <div class="container">
        <a href="/" class="btn btn-outline right">Create a gist now</a>
        <p class="lead">
          Instantly share code, notes, and snippets.
        </p>
      </div>
    </div>


  <div class="gisthead pagehead repohead instapaper_ignore readability-menu experiment-repo-nav">
    <div class="container">
        

<div class="container repohead-details-container">

  <ul class="pagehead-actions">


    <li>
        <a href="/login?return_to=https%3A%2F%2Fgist.github.com%2Fseanwupi%2Fbf364ed692f059ccc5ef1839212a6834" aria-label="You must be signed in to star a gist" class="btn btn-sm btn-with-count tooltipped tooltipped-n" rel="nofollow">
    <svg aria-hidden="true" class="octicon octicon-star" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path d="M14 6l-4.9-.64L7 1 4.9 5.36 0 6l3.6 3.26L2.67 14 7 11.67 11.33 14l-.93-4.74z"></path></svg>
    Star
</a>
  <a href="/seanwupi/bf364ed692f059ccc5ef1839212a6834/stargazers" class="social-count">
    0
</a>
    </li>

      <li>
          <a href="/login?return_to=https%3A%2F%2Fgist.github.com%2Fseanwupi%2Fbf364ed692f059ccc5ef1839212a6834" aria-label="You must be signed in to fork a gist" class="btn btn-sm btn-with-count tooltipped tooltipped-n" rel="nofollow">
    <svg aria-hidden="true" class="octicon octicon-repo-forked" height="16" version="1.1" viewBox="0 0 10 16" width="10"><path d="M8 1a1.993 1.993 0 0 0-1 3.72V6L5 8 3 6V4.72A1.993 1.993 0 0 0 2 1a1.993 1.993 0 0 0-1 3.72V6.5l3 3v1.78A1.993 1.993 0 0 0 5 15a1.993 1.993 0 0 0 1-3.72V9.5l3-3V4.72A1.993 1.993 0 0 0 8 1zM2 4.2C1.34 4.2.8 3.65.8 3c0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2zm3 10c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2zm3-10c-.66 0-1.2-.55-1.2-1.2 0-.65.55-1.2 1.2-1.2.65 0 1.2.55 1.2 1.2 0 .65-.55 1.2-1.2 1.2z"></path></svg>
    Fork
</a>
  <a href="/seanwupi/bf364ed692f059ccc5ef1839212a6834/forks" class="social-count">
    0
</a>
      </li>

  </ul>

  <h1 class="secret css-truncate">
    <img alt="@seanwupi" class="avatar gist-avatar" height="26" src="https://avatars3.githubusercontent.com/u/2498406?v=3&amp;s=52" width="26" />
    <span class="author"><a href="/seanwupi" class="url fn" rel="author"><span itemprop="author">seanwupi</span></a></span><!--
        --><span class="path-divider">/</span><!--
        --><strong itemprop="name" class="gist-header-title css-truncate-target"><a href="/seanwupi/bf364ed692f059ccc5ef1839212a6834">Pinhole.cpp</a></strong>
      <span class="gist-secret-label">secret</span>

    <div class="gist-timestamp">Created <time-ago datetime="2016-06-13T09:21:02Z">Jun 13, 2016</time-ago></div>
  </h1>
</div>

<div class="container gist-file-navigation">
  <div class="right file-navigation-options" data-multiple>

    <div class="file-navigation-option">
  <input type="hidden" name="protocol_type" value="clone">

  <div class="select-menu js-menu-container js-select-menu">
    <div class="input-group js-select-button js-zeroclipboard-container">
      <div class="input-group-button">
  <button type="button" class="btn btn-sm select-menu-button js-menu-target" data-ga-click="Repository, clone Embed, location:repo overview">
    Embed
  </button>
</div>
<input type="text" class="form-control input-monospace input-sm js-zeroclipboard-target js-url-field" value="&lt;script src=&quot;https://gist.github.com/seanwupi/bf364ed692f059ccc5ef1839212a6834.js&quot;&gt;&lt;/script&gt;" aria-label="Clone this repository at &lt;script src=&quot;https://gist.github.com/seanwupi/bf364ed692f059ccc5ef1839212a6834.js&quot;&gt;&lt;/script&gt;" readonly>
<div class="input-group-button">
  <button aria-label="Copy to clipboard" class="js-zeroclipboard btn btn-sm zeroclipboard-button tooltipped tooltipped-s" data-copied-hint="Copied!" type="button"><svg aria-hidden="true" class="octicon octicon-clippy" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path d="M2 13h4v1H2v-1zm5-6H2v1h5V7zm2 3V8l-3 3 3 3v-2h5v-2H9zM4.5 9H2v1h2.5V9zM2 12h2.5v-1H2v1zm9 1h1v2c-.02.28-.11.52-.3.7-.19.18-.42.28-.7.3H1c-.55 0-1-.45-1-1V4c0-.55.45-1 1-1h3c0-1.11.89-2 2-2 1.11 0 2 .89 2 2h3c.55 0 1 .45 1 1v5h-1V6H1v9h10v-2zM2 5h8c0-.55-.45-1-1-1H8c-.55 0-1-.45-1-1s-.45-1-1-1-1 .45-1 1-.45 1-1 1H3c-.55 0-1 .45-1 1z"></path></svg></button>
</div>

    </div>

    <div class="select-menu-modal-holder">
      <div class="select-menu-modal js-menu-content" aria-hidden="true">
        <div class="select-menu-header">
          <svg aria-label="Close" class="octicon octicon-x js-menu-close" height="16" role="img" version="1.1" viewBox="0 0 12 16" width="12"><path d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48z"></path></svg>
          <span class="select-menu-title">What would you like to do?</span>
        </div>

        <div class="select-menu-list js-navigation-container" role="menu">
            <div class="select-menu-item js-navigation-item selected" role="menuitem" tabindex="0">
              <svg aria-hidden="true" class="octicon octicon-check select-menu-item-icon" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5z"></path></svg>
              <div class="select-menu-item-text">
                <input type="radio" name="protocol_selector" value="embed" checked>
                <span class="select-menu-item-heading">
                  
                  Embed
                </span>
                  <span class="description">
                    Embed this gist in your website.
                  </span>
                <span class="js-select-button-text hidden-select-button-text">
                  <div class="input-group-button">
  <button type="button" class="btn btn-sm select-menu-button js-menu-target" data-ga-click="Repository, clone Embed, location:repo overview">
    Embed
  </button>
</div>
<input type="text" class="form-control input-monospace input-sm js-zeroclipboard-target js-url-field" value="&lt;script src=&quot;https://gist.github.com/seanwupi/bf364ed692f059ccc5ef1839212a6834.js&quot;&gt;&lt;/script&gt;" aria-label="Clone this repository at &lt;script src=&quot;https://gist.github.com/seanwupi/bf364ed692f059ccc5ef1839212a6834.js&quot;&gt;&lt;/script&gt;" readonly>
<div class="input-group-button">
  <button aria-label="Copy to clipboard" class="js-zeroclipboard btn btn-sm zeroclipboard-button tooltipped tooltipped-s" data-copied-hint="Copied!" type="button"><svg aria-hidden="true" class="octicon octicon-clippy" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path d="M2 13h4v1H2v-1zm5-6H2v1h5V7zm2 3V8l-3 3 3 3v-2h5v-2H9zM4.5 9H2v1h2.5V9zM2 12h2.5v-1H2v1zm9 1h1v2c-.02.28-.11.52-.3.7-.19.18-.42.28-.7.3H1c-.55 0-1-.45-1-1V4c0-.55.45-1 1-1h3c0-1.11.89-2 2-2 1.11 0 2 .89 2 2h3c.55 0 1 .45 1 1v5h-1V6H1v9h10v-2zM2 5h8c0-.55-.45-1-1-1H8c-.55 0-1-.45-1-1s-.45-1-1-1-1 .45-1 1-.45 1-1 1H3c-.55 0-1 .45-1 1z"></path></svg></button>
</div>

                </span>
              </div>
            </div>
            <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
              <svg aria-hidden="true" class="octicon octicon-check select-menu-item-icon" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5z"></path></svg>
              <div class="select-menu-item-text">
                <input type="radio" name="protocol_selector" value="share" >
                <span class="select-menu-item-heading">
                  
                  Share
                </span>
                  <span class="description">
                    Copy sharable URL for this gist.
                  </span>
                <span class="js-select-button-text hidden-select-button-text">
                  <div class="input-group-button">
  <button type="button" class="btn btn-sm select-menu-button js-menu-target" data-ga-click="Repository, clone Share, location:repo overview">
    Share
  </button>
</div>
<input type="text" class="form-control input-monospace input-sm js-zeroclipboard-target js-url-field" value="https://gist.github.com/seanwupi/bf364ed692f059ccc5ef1839212a6834" aria-label="Clone this repository at https://gist.github.com/seanwupi/bf364ed692f059ccc5ef1839212a6834" readonly>
<div class="input-group-button">
  <button aria-label="Copy to clipboard" class="js-zeroclipboard btn btn-sm zeroclipboard-button tooltipped tooltipped-s" data-copied-hint="Copied!" type="button"><svg aria-hidden="true" class="octicon octicon-clippy" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path d="M2 13h4v1H2v-1zm5-6H2v1h5V7zm2 3V8l-3 3 3 3v-2h5v-2H9zM4.5 9H2v1h2.5V9zM2 12h2.5v-1H2v1zm9 1h1v2c-.02.28-.11.52-.3.7-.19.18-.42.28-.7.3H1c-.55 0-1-.45-1-1V4c0-.55.45-1 1-1h3c0-1.11.89-2 2-2 1.11 0 2 .89 2 2h3c.55 0 1 .45 1 1v5h-1V6H1v9h10v-2zM2 5h8c0-.55-.45-1-1-1H8c-.55 0-1-.45-1-1s-.45-1-1-1-1 .45-1 1-.45 1-1 1H3c-.55 0-1 .45-1 1z"></path></svg></button>
</div>

                </span>
              </div>
            </div>
            <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
              <svg aria-hidden="true" class="octicon octicon-check select-menu-item-icon" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path d="M12 5l-8 8-4-4 1.5-1.5L4 10l6.5-6.5z"></path></svg>
              <div class="select-menu-item-text">
                <input type="radio" name="protocol_selector" value="http" >
                <span class="select-menu-item-heading">
                  Clone via
                  HTTPS
                </span>
                  <span class="description">
                    Clone with Git or checkout with SVN using the repository's web address.
                  </span>
                <span class="js-select-button-text hidden-select-button-text">
                  <div class="input-group-button">
  <button type="button" class="btn btn-sm select-menu-button js-menu-target" data-ga-click="Repository, clone HTTPS, location:repo overview">
    HTTPS
  </button>
</div>
<input type="text" class="form-control input-monospace input-sm js-zeroclipboard-target js-url-field" value="https://gist.github.com/bf364ed692f059ccc5ef1839212a6834.git" aria-label="Clone this repository at https://gist.github.com/bf364ed692f059ccc5ef1839212a6834.git" readonly>
<div class="input-group-button">
  <button aria-label="Copy to clipboard" class="js-zeroclipboard btn btn-sm zeroclipboard-button tooltipped tooltipped-s" data-copied-hint="Copied!" type="button"><svg aria-hidden="true" class="octicon octicon-clippy" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path d="M2 13h4v1H2v-1zm5-6H2v1h5V7zm2 3V8l-3 3 3 3v-2h5v-2H9zM4.5 9H2v1h2.5V9zM2 12h2.5v-1H2v1zm9 1h1v2c-.02.28-.11.52-.3.7-.19.18-.42.28-.7.3H1c-.55 0-1-.45-1-1V4c0-.55.45-1 1-1h3c0-1.11.89-2 2-2 1.11 0 2 .89 2 2h3c.55 0 1 .45 1 1v5h-1V6H1v9h10v-2zM2 5h8c0-.55-.45-1-1-1H8c-.55 0-1-.45-1-1s-.45-1-1-1-1 .45-1 1-.45 1-1 1H3c-.55 0-1 .45-1 1z"></path></svg></button>
</div>

                </span>
              </div>
            </div>
        </div>
        <div class="select-menu-list" role="menu">
          <a class="select-menu-item select-menu-action" href="https://help.github.com/articles/which-remote-url-should-i-use" target="_blank">
            <svg aria-hidden="true" class="octicon octicon-question select-menu-item-icon" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path d="M6 10h2v2H6v-2zm4-3.5C10 8.64 8 9 8 9H6c0-.55.45-1 1-1h.5c.28 0 .5-.22.5-.5v-1c0-.28-.22-.5-.5-.5h-1c-.28 0-.5.22-.5.5V7H4c0-1.5 1.5-3 3-3s3 1 3 2.5zM7 2.3c3.14 0 5.7 2.56 5.7 5.7s-2.56 5.7-5.7 5.7A5.71 5.71 0 0 1 1.3 8c0-3.14 2.56-5.7 5.7-5.7zM7 1C3.14 1 0 4.14 0 8s3.14 7 7 7 7-3.14 7-7-3.14-7-7-7z"></path></svg>
            <div class="select-menu-item-text">
              Learn more about clone URLs
            </div>
          </a>
        </div>
      </div>
    </div>
  </div>
</div>


    <div class="file-navigation-option">
</div>


    <div class="file-navigation-option">
      <a href="/seanwupi/bf364ed692f059ccc5ef1839212a6834/archive/a419445ddb446d9f65857344e6645479d5c872e8.zip"
          class="btn btn-sm"
          rel="nofollow"
          data-ga-click="Gist, download zip, location:gist overview">
        Download ZIP
      </a>
    </div>
  </div>

  <div class="left">
    <nav class="reponav js-repo-nav js-sidenav-container-pjax"
     role="navigation"
     data-pjax="#gist-pjax-container">

  <a href="/seanwupi/bf364ed692f059ccc5ef1839212a6834" aria-label="Code" aria-selected="true" class="js-selected-navigation-item selected reponav-item" data-hotkey="g c" data-pjax="true" data-selected-links="gist_code /seanwupi/bf364ed692f059ccc5ef1839212a6834">
    <svg aria-hidden="true" class="octicon octicon-code" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path d="M9.5 3L8 4.5 11.5 8 8 11.5 9.5 13 14 8 9.5 3zm-5 0L0 8l4.5 5L6 11.5 2.5 8 6 4.5 4.5 3z"></path></svg>
    Code
</a>
    <a href="/seanwupi/bf364ed692f059ccc5ef1839212a6834/revisions" aria-label="Revisions" class="js-selected-navigation-item reponav-item" data-hotkey="g r" data-pjax="true" data-selected-links="gist_revisions /seanwupi/bf364ed692f059ccc5ef1839212a6834/revisions">
      <svg aria-hidden="true" class="octicon octicon-git-commit" height="16" version="1.1" viewBox="0 0 14 16" width="14"><path d="M10.86 7c-.45-1.72-2-3-3.86-3-1.86 0-3.41 1.28-3.86 3H0v2h3.14c.45 1.72 2 3 3.86 3 1.86 0 3.41-1.28 3.86-3H14V7h-3.14zM7 10.2c-1.22 0-2.2-.98-2.2-2.2 0-1.22.98-2.2 2.2-2.2 1.22 0 2.2.98 2.2 2.2 0 1.22-.98 2.2-2.2 2.2z"></path></svg>
      Revisions
      <span class="counter">1</span>
</a>

</nav>

  </div>
</div>


    </div><!-- /.container -->
  </div><!-- /.repohead -->

<div class="container new-discussion-timeline experiment-repo-nav">
  <div class="repository-content gist-content">
    



<div>
  <div class="repository-meta js-details-container">
</div>


      <div class="js-gist-file-update-container js-task-list-container file-box">
  <div id="file-pinhole-cpp" class="file">
      <div class="file-header">
        <div class="file-actions">

          <a href="/seanwupi/bf364ed692f059ccc5ef1839212a6834/raw/a419445ddb446d9f65857344e6645479d5c872e8/Pinhole.cpp" class="btn btn-sm ">Raw</a>
        </div>
        <div class="file-info">
          <span class="icon">
            <svg aria-hidden="true" class="octicon octicon-gist" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path d="M7.5 5L10 7.5 7.5 10l-.75-.75L8.5 7.5 6.75 5.75 7.5 5zm-3 0L2 7.5 4.5 10l.75-.75L3.5 7.5l1.75-1.75L4.5 5zM0 13V2c0-.55.45-1 1-1h10c.55 0 1 .45 1 1v11c0 .55-.45 1-1 1H1c-.55 0-1-.45-1-1zm1 0h10V2H1v11z"></path></svg>
          </span>
          <a class="tooltipped tooltipped-s css-truncate" aria-label="Permalink" href="#file-pinhole-cpp">
            <strong class="user-select-contain gist-blob-name css-truncate-target">
              Pinhole.cpp
            </strong>
          </a>
        </div>
      </div>
    

  <div itemprop="text" class="blob-wrapper data type-c">
      <table class="highlight tab-size js-file-line-container" data-tab-size="8">
      <tr>
        <td id="file-pinhole-cpp-L1" class="blob-num js-line-number" data-line-number="1"></td>
        <td id="file-pinhole-cpp-LC1" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">include</span> <span class="pl-s"><span class="pl-pds">&lt;</span>stdlib.h<span class="pl-pds">&gt;</span></span></td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L2" class="blob-num js-line-number" data-line-number="2"></td>
        <td id="file-pinhole-cpp-LC2" class="blob-code blob-code-inner js-file-line">#<span class="pl-k">include</span> <span class="pl-s"><span class="pl-pds">&quot;</span>pin.H<span class="pl-pds">&quot;</span></span></td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L3" class="blob-num js-line-number" data-line-number="3"></td>
        <td id="file-pinhole-cpp-LC3" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L4" class="blob-num js-line-number" data-line-number="4"></td>
        <td id="file-pinhole-cpp-LC4" class="blob-code blob-code-inner js-file-line">VOID <span class="pl-en">check_syscall</span>(ADDRINT rax, ADDRINT rdi)</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L5" class="blob-num js-line-number" data-line-number="5"></td>
        <td id="file-pinhole-cpp-LC5" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L6" class="blob-num js-line-number" data-line-number="6"></td>
        <td id="file-pinhole-cpp-LC6" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">static</span> <span class="pl-k">int</span> is_syscall_impossible = <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L7" class="blob-num js-line-number" data-line-number="7"></td>
        <td id="file-pinhole-cpp-LC7" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">if</span>(is_syscall_impossible){</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L8" class="blob-num js-line-number" data-line-number="8"></td>
        <td id="file-pinhole-cpp-LC8" class="blob-code blob-code-inner js-file-line">        <span class="pl-c1">PIN_ERROR</span>(<span class="pl-s"><span class="pl-pds">&quot;</span>invalid syscall<span class="pl-cce">\n</span><span class="pl-pds">&quot;</span></span>);</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L9" class="blob-num js-line-number" data-line-number="9"></td>
        <td id="file-pinhole-cpp-LC9" class="blob-code blob-code-inner js-file-line">        <span class="pl-c1">exit</span>(-<span class="pl-c1">1</span>);</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L10" class="blob-num js-line-number" data-line-number="10"></td>
        <td id="file-pinhole-cpp-LC10" class="blob-code blob-code-inner js-file-line">    }<span class="pl-k">else</span>{</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L11" class="blob-num js-line-number" data-line-number="11"></td>
        <td id="file-pinhole-cpp-LC11" class="blob-code blob-code-inner js-file-line">        <span class="pl-k">if</span>(rax == <span class="pl-c1">3</span> &amp;&amp; rdi == <span class="pl-c1">31337</span>){   <span class="pl-c">// sys_close(31337)</span></td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L12" class="blob-num js-line-number" data-line-number="12"></td>
        <td id="file-pinhole-cpp-LC12" class="blob-code blob-code-inner js-file-line">            is_syscall_impossible = ~<span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L13" class="blob-num js-line-number" data-line-number="13"></td>
        <td id="file-pinhole-cpp-LC13" class="blob-code blob-code-inner js-file-line">        }</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L14" class="blob-num js-line-number" data-line-number="14"></td>
        <td id="file-pinhole-cpp-LC14" class="blob-code blob-code-inner js-file-line">    }</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L15" class="blob-num js-line-number" data-line-number="15"></td>
        <td id="file-pinhole-cpp-LC15" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L16" class="blob-num js-line-number" data-line-number="16"></td>
        <td id="file-pinhole-cpp-LC16" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L17" class="blob-num js-line-number" data-line-number="17"></td>
        <td id="file-pinhole-cpp-LC17" class="blob-code blob-code-inner js-file-line">VOID <span class="pl-en">insert_hooks</span>(INS ins, VOID *val)</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L18" class="blob-num js-line-number" data-line-number="18"></td>
        <td id="file-pinhole-cpp-LC18" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L19" class="blob-num js-line-number" data-line-number="19"></td>
        <td id="file-pinhole-cpp-LC19" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">if</span>(<span class="pl-c1">INS_IsSyscall</span>(ins)){</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L20" class="blob-num js-line-number" data-line-number="20"></td>
        <td id="file-pinhole-cpp-LC20" class="blob-code blob-code-inner js-file-line">        <span class="pl-c">// check syscall</span></td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L21" class="blob-num js-line-number" data-line-number="21"></td>
        <td id="file-pinhole-cpp-LC21" class="blob-code blob-code-inner js-file-line">        <span class="pl-c1">INS_InsertCall</span>(ins, IPOINT_BEFORE, (AFUNPTR)check_syscall,</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L22" class="blob-num js-line-number" data-line-number="22"></td>
        <td id="file-pinhole-cpp-LC22" class="blob-code blob-code-inner js-file-line">            IARG_REG_VALUE, REG_RAX, IARG_REG_VALUE, REG_RDI, IARG_END);</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L23" class="blob-num js-line-number" data-line-number="23"></td>
        <td id="file-pinhole-cpp-LC23" class="blob-code blob-code-inner js-file-line">    }</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L24" class="blob-num js-line-number" data-line-number="24"></td>
        <td id="file-pinhole-cpp-LC24" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L25" class="blob-num js-line-number" data-line-number="25"></td>
        <td id="file-pinhole-cpp-LC25" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L26" class="blob-num js-line-number" data-line-number="26"></td>
        <td id="file-pinhole-cpp-LC26" class="blob-code blob-code-inner js-file-line"><span class="pl-k">int</span> <span class="pl-en">main</span>(<span class="pl-k">int</span> argc, <span class="pl-k">char</span> *argv[])</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L27" class="blob-num js-line-number" data-line-number="27"></td>
        <td id="file-pinhole-cpp-LC27" class="blob-code blob-code-inner js-file-line">{</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L28" class="blob-num js-line-number" data-line-number="28"></td>
        <td id="file-pinhole-cpp-LC28" class="blob-code blob-code-inner js-file-line">    <span class="pl-c1">PIN_Init</span>(argc, argv);</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L29" class="blob-num js-line-number" data-line-number="29"></td>
        <td id="file-pinhole-cpp-LC29" class="blob-code blob-code-inner js-file-line">    <span class="pl-c1">INS_AddInstrumentFunction</span>(insert_hooks, <span class="pl-c1">NULL</span>);</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L30" class="blob-num js-line-number" data-line-number="30"></td>
        <td id="file-pinhole-cpp-LC30" class="blob-code blob-code-inner js-file-line">    <span class="pl-c1">PIN_StartProgram</span>();</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L31" class="blob-num js-line-number" data-line-number="31"></td>
        <td id="file-pinhole-cpp-LC31" class="blob-code blob-code-inner js-file-line">
</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L32" class="blob-num js-line-number" data-line-number="32"></td>
        <td id="file-pinhole-cpp-LC32" class="blob-code blob-code-inner js-file-line">    <span class="pl-k">return</span> <span class="pl-c1">0</span>;</td>
      </tr>
      <tr>
        <td id="file-pinhole-cpp-L33" class="blob-num js-line-number" data-line-number="33"></td>
        <td id="file-pinhole-cpp-LC33" class="blob-code blob-code-inner js-file-line">}</td>
      </tr>
</table>

  </div>

  </div>
  
</div>


  <a name="comments"></a>
  <div class="discussion-timeline gist-discussion-timeline js-quote-selection-container ">
    <div class="js-discussion js-socket-channel" data-channel="tenant:1:marked-as-read:gist:36731757">
      




<!-- Rendered timeline since 2016-06-13 02:21:03 -->
<div id="partial-timeline-marker"
      class="js-timeline-marker js-updatable-content"
      data-url="/seanwupi/bf364ed692f059ccc5ef1839212a6834/show_partial?partial=gist%2Ftimeline_marker&amp;since=1465809663"
      data-last-modified="Mon, 13 Jun 2016 09:21:03 GMT"
      >
</div>


      <div class="discussion-timeline-actions">
          <div class="signed-out-comment">
    <a href="/join?source=comment-gist" class="btn btn-primary" rel="nofollow">Sign up for free</a>
    <strong>to join this conversation on GitHub</strong>.
    Already have an account?
    <a href="/login?return_to=https%3A%2F%2Fgist.github.com%2Fseanwupi%2Fbf364ed692f059ccc5ef1839212a6834" rel="nofollow">Sign in to comment</a>
</div>

      </div>
    </div>
  </div>
</div>
  </div>

  <div class="modal-backdrop js-touch-events"></div>
</div><!-- /.container -->

    </div><!-- /.gist-pjax-container -->
  </div>

    </div>

        <div class="container site-footer-container">
  <div class="site-footer" role="contentinfo">
    <ul class="site-footer-links right">
        <li><a href="https://status.github.com/" data-ga-click="Footer, go to status, text:status">Status</a></li>
      <li><a href="https://developer.github.com" data-ga-click="Footer, go to api, text:api">API</a></li>
      <li><a href="https://training.github.com" data-ga-click="Footer, go to training, text:training">Training</a></li>
      <li><a href="https://shop.github.com" data-ga-click="Footer, go to shop, text:shop">Shop</a></li>
        <li><a href="https://github.com/blog" data-ga-click="Footer, go to blog, text:blog">Blog</a></li>
        <li><a href="https://github.com/about" data-ga-click="Footer, go to about, text:about">About</a></li>

    </ul>

    <a href="https://github.com" aria-label="Homepage" class="site-footer-mark" title="GitHub">
      <svg aria-hidden="true" class="octicon octicon-mark-github" height="24" version="1.1" viewBox="0 0 16 16" width="24"><path d="M8 0C3.58 0 0 3.58 0 8c0 3.54 2.29 6.53 5.47 7.59.4.07.55-.17.55-.38 0-.19-.01-.82-.01-1.49-2.01.37-2.53-.49-2.69-.94-.09-.23-.48-.94-.82-1.13-.28-.15-.68-.52-.01-.53.63-.01 1.08.58 1.23.82.72 1.21 1.87.87 2.33.66.07-.52.28-.87.51-1.07-1.78-.2-3.64-.89-3.64-3.95 0-.87.31-1.59.82-2.15-.08-.2-.36-1.02.08-2.12 0 0 .67-.21 2.2.82.64-.18 1.32-.27 2-.27.68 0 1.36.09 2 .27 1.53-1.04 2.2-.82 2.2-.82.44 1.1.16 1.92.08 2.12.51.56.82 1.27.82 2.15 0 3.07-1.87 3.75-3.65 3.95.29.25.54.73.54 1.48 0 1.07-.01 1.93-.01 2.2 0 .21.15.46.55.38A8.013 8.013 0 0 0 16 8c0-4.42-3.58-8-8-8z"></path></svg>
</a>
    <ul class="site-footer-links">
      <li>&copy; 2016 <span title="0.06812s from github-fe117-cp1-prd.iad.github.net">GitHub</span>, Inc.</li>
        <li><a href="https://github.com/site/terms" data-ga-click="Footer, go to terms, text:terms">Terms</a></li>
        <li><a href="https://github.com/site/privacy" data-ga-click="Footer, go to privacy, text:privacy">Privacy</a></li>
        <li><a href="https://github.com/security" data-ga-click="Footer, go to security, text:security">Security</a></li>
        <li><a href="https://github.com/contact" data-ga-click="Footer, go to contact, text:contact">Contact</a></li>
        <li><a href="https://help.github.com" data-ga-click="Footer, go to help, text:help">Help</a></li>
    </ul>
  </div>
</div>



    

    <div id="ajax-error-message" class="ajax-error-message flash flash-error">
      <svg aria-hidden="true" class="octicon octicon-alert" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path d="M8.865 1.52c-.18-.31-.51-.5-.87-.5s-.69.19-.87.5L.275 13.5c-.18.31-.18.69 0 1 .19.31.52.5.87.5h13.7c.36 0 .69-.19.86-.5.17-.31.18-.69.01-1L8.865 1.52zM8.995 13h-2v-2h2v2zm0-3h-2V6h2v4z"></path></svg>
      <button type="button" class="flash-close js-flash-close js-ajax-error-dismiss" aria-label="Dismiss error">
        <svg aria-hidden="true" class="octicon octicon-x" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48z"></path></svg>
      </button>
      Something went wrong with that request. Please try again.
    </div>


      
      <script crossorigin="anonymous" src="https://assets-cdn.github.com/assets/frameworks-752d672b75dd3528039ea14e78d5638b9126eeb7de38701f46091862c63d73da.js"></script>
      <script async="async" crossorigin="anonymous" src="https://assets-cdn.github.com/assets/github-ba6a49a5b72a3b71afb5394ab11a0b1a4d15cdb5877879000bf1bca10c19e310.js"></script>
      
      
      
      
      
      
    <div class="js-stale-session-flash stale-session-flash flash flash-warn flash-banner hidden">
      <svg aria-hidden="true" class="octicon octicon-alert" height="16" version="1.1" viewBox="0 0 16 16" width="16"><path d="M8.865 1.52c-.18-.31-.51-.5-.87-.5s-.69.19-.87.5L.275 13.5c-.18.31-.18.69 0 1 .19.31.52.5.87.5h13.7c.36 0 .69-.19.86-.5.17-.31.18-.69.01-1L8.865 1.52zM8.995 13h-2v-2h2v2zm0-3h-2V6h2v4z"></path></svg>
      <span class="signed-in-tab-flash">You signed in with another tab or window. <a href="">Reload</a> to refresh your session.</span>
      <span class="signed-out-tab-flash">You signed out in another tab or window. <a href="">Reload</a> to refresh your session.</span>
    </div>
    <div class="facebox" id="facebox" style="display:none;">
  <div class="facebox-popup">
    <div class="facebox-content" role="dialog" aria-labelledby="facebox-header" aria-describedby="facebox-description">
    </div>
    <button type="button" class="facebox-close js-facebox-close" aria-label="Close modal">
      <svg aria-hidden="true" class="octicon octicon-x" height="16" version="1.1" viewBox="0 0 12 16" width="12"><path d="M7.48 8l3.75 3.75-1.48 1.48L6 9.48l-3.75 3.75-1.48-1.48L4.52 8 .77 4.25l1.48-1.48L6 6.52l3.75-3.75 1.48 1.48z"></path></svg>
    </button>
  </div>
</div>

  </body>
</html>

