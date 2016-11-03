package Composite;

public enum Style {
	BOLD {
		@Override
		public String wrap(String str) {
			return "<b>" + str + "</b>";
		}
	}, ITALIC {
		@Override
		public String wrap(String str) {
			return "<i>" + str + "</i>";
		}
	}, UNDERLINE {
		@Override
		public String wrap(String str) {
			return "<l>" + str + "</l>";
		}
	}, NONE {
		@Override
		public String wrap(String str) {
			return str;
		}
	};
	
	public abstract String wrap(String str);
}