Pod::Spec.new do |s|
  s.name         = "DDRemoteLogger"
  s.version      = “1.0.0”
  s.summary      = "A simple real-time remote UDP logging for iOS application."
  s.homepage     = "https://github.com/ulhas/DDRemoteLogger"
  s.license      = { :type => "MIT" }
  s.author             = { "Ulhas Mandrawadkar" => "ulhas.sm@gmail.com" }
  s.social_media_url   = "http://twitter.com/ulhas_sm"
  s.platform     = :ios, "5.0"
  s.source       = { :git => "https://github.com/ulhas/DDRemoteLogger.git", :tag => “1.0.0” }
  s.source_files  = "*.{h,m}"
  s.requires_arc = true
  s.dependency      'CocoaLumberjack', '>= 1.6'
  s.dependency      'CocoaAsyncSocket', '~> 7.3.4'
end
